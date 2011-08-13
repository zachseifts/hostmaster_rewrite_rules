<?php

/**
 * Implementation of hook_hosting_site_context_options().
 */
function rewrite_rules_hosting_site_context_options(&$task) {
  if (isset($task->ref->redirect_rules)) {
    $task->context_options['redirect_rules'] = $task->ref->redirect_rules;
  }
}

/**
 * Implementation of hook_drush_context_import().
 */
function rewrite_rules_drush_context_import($context, &$node) {
  if ($context->type == 'site') {
    if (isset($context->redirect_rules)) {
      $node->redirect_rules = $context->redirect_rules;
    }
  }

}
