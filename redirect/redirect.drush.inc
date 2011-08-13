<?php

/**
 * @file
 *   The redirect provision service.
 */

include_once(dirname(__FILE__) . '/../provision.service.inc');

/**
 * Expose the service type this extension defines to provision.
 *
 * @return
 *   An array with the service type the key, and the default implementation the value.
 */
function redirect_provision_services() {
  return array('redirect' => NULL);
}

/**
 * The redirect service base class.
 */
class provisionService_redirect extends provisionService {
  public $service = 'redirect';

  /**
   * Add the redirect_path property to the site context.
   */
  static function subscribe_site($context) {
    $context->setProperty('redirect_rules');
  }
}

/**
 * Implementation of hook_provision_apache_vhost_config().
 *
 */
function redirect_provision_apache_vhost_config($uri, $data) {
  $lines = array();
  if (d()->type == 'site') {
    if (!empty(d()->redirect_rules)) {
      $lines[] = '# Rewrite Rules';
      $lines[] = d()->redirect_rules;
    }
  }

  return implode($lines, "\n");
}
