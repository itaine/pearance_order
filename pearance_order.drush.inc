<?php
/**
* Implementation of drush_hook_pre_hosting_task()
* Send the site and user attributes to the backend for processing.
*/
function drush_pearance_order_pre_hosting_task() {
  $task =& drush_get_context('HOSTING_TASK');
  if ($task->ref->type == 'site' && ($task->task_type == 'install' || $task->task_type == 'verify')) {
    
    $client = node_load($task->ref->client);
    $vid = $task->ref->vid;
    
    $task->options['client_name'] = $client->name;
    $task->options['client_email'] = $client->client_email;  
    $task->options['theme'] = $task->ref->theme;
  }
}