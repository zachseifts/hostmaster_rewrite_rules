# Hostmaster Rewrite Rules

Adds a rewrite\_rules context to the Aegir site context to allow you to store rewrite rules along with the site information.

hello #dcavl folks!


## Installation

    cd /var/aegir/src
    git clone git://github.com/zachseifts/hostmaster_rewrite_rules.git 
    cd /var/aegir/.drush/provision
    ln -s /var/aegir/src/hostmaster_rewrite_rules/redirect .
    cd /var/aegir/hostmaster-6.x-1.2/profiles/hostmaster/modules
    ln -s /var/aegir/src/hostmaster_rewrite_rules/rewrite_rules .

Enable the module and you should have the ability to add rewrite rules to your vhost file.

## Rules format

Only enter valid rewrite rules, ex:

    RewriteRule ^path/to/old/resource /path/to/new/resource [L,R=301]
    RewriteRule ^path/to/old/resource2 /path/to/new/resource2 [L,R=301]

If you find that your rewrite rules fail to work after you verify your site you might have an error in one of your rules.

