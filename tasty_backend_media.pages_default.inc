<?php

/**
 * Implements hook_default_page_manager_pages().
 */
function tasty_backend_media_default_page_manager_pages() {
  
  $pages = array();
  
  // Manage Files context admin administrative section.
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'manage_files';
  $page->task = 'page';
  $page->admin_title = 'Manage Files';
  $page->admin_description = 'Context admin administrative section to manage files.';
  $page->path = 'admin/manage/files';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'administer files',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'or',
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Files',
    'name' => 'navigation',
    'weight' => '2',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_manage_files_menu_context';
  $handler->task = 'page';
  $handler->subtask = 'manage_files';
  $handler->handler = 'menu_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Context Admin',
    'no_blocks' => FALSE,
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'context_admin_options' => 'admin_section',
  );
  $page->default_handlers[$handler->name] = $handler;
  
  $pages['manage_files'] = $page;
  
  return $pages;
}