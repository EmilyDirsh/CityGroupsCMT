<?php
/**
 * Stub functions, orginally taken from Fusion Core.
 */

/**
 * HTML preprocessing
 */
function citygroups_preprocess_html(&$vars) {
  global $theme_key, $user;

  // Add to array of helpful body classes
  if (isset($vars['node'])) {
    $vars['classes_array'][] = ($vars['node']) ? 'full-node' : '';                                            // Full node
    $vars['classes_array'][] = (($vars['node']->type == 'forum') || (arg(0) == 'forum')) ? 'forum' : '';      // Forum page
  }
  else {
    $vars['classes_array'][] = (arg(0) == 'forum') ? 'forum' : '';                                            // Forum page
  }

  // Add a unique page id
  $vars['body_id'] = 'pid-' . strtolower(preg_replace('/[^a-zA-Z0-9-]+/', '-', drupal_get_path_alias($_GET['q'])));
}

/**
 * Maintenance page preprocessing
 */
function  citygroups_preprocess_maintenance_page(&$vars) {
  if (class_exists('Database', FALSE)) {
    citygroups_preprocess_html($vars);  // set html vars (html.tpl.php is in maintenance-page.tpl.php)
    citygroups_preprocess_page($vars);  // set page vars
  }
}

/**
 * Generate count of groups and use it in the slogan.
 */
function citygroups_slogan_count() {
  $count = "350";
  $city = "Seattle";
  $slogan = t("A public directory of over ") . $count . t(" community groups in ") . $city . ".";
  return $slogan;
}

/**
 * Page preprocessing
 */
function citygroups_preprocess_page(&$vars) {
/*   $vars['page_path'] = isset($_GET['q']) ? $_GET['q'] : '<front>'; */
  
  // @TODO Temp declaration of section here to prevent some bugs.
  if(empty($vars['section'])) {
    $vars['section'] = array();
    $vars['section']['section_name'] = '';
  }
  // Create variables from theme settings (set in .info file)
  if(empty($vars['sitename'])) {
    $vars['sitename'] = theme_get_setting('sitename');
  }
  if(empty($vars['site_slogan'])) {
    $vars['site_slogan'] = theme_get_setting('site_slogan');
  // Completely override slogan with count of number of groups.
  //$vars['site_slogan'] = citygroups_slogan_count();
  }

  if(empty($vars['logo'])) {
    $vars['logo_image_link'] = theme_get_setting('logo_image_link');
    $vars['logo'] = '<a href="/"><img src="/' . drupal_get_path('theme', 'citygroups') . '/' . $vars['logo_image_link'] . '" /></a>';
  }

  $vars['prealpha'] = '<div class="prealpha">PRE-ALPHA</div>';
  
  // If sidebars are empty, make main region full width.
  if(count($vars['page']['sidebar_first']) == 0 && count($vars['page']['sidebar_second']) == 0) {
    $vars['main_region_width'] = 'grid_16';
  }
  else {
    $vars['main_region_width'] = 'grid_11';
  }

  // Create some resource variables

  // Create login link
  $account_text = t('Sign in');
  global $user;
  if ($user->uid > 0) {
    // User is logged in
    $account_text = t('My Account');
  }
  $vars['account_link'] = l($account_text, 'user', array(
    'attributes' => array(
      'id' => 'signin',
    )
  ));
  
  // Hardcoded site names
  switch ($_SERVER['HTTP_HOST']) {
    case 'philly.citygroups.org':
      $vars['sub_site_name'] = t('Philadelphia');
      break;
      
    case 'seattle.citygroups.org':
      $vars['sub_site_name'] = t('Seattle');
      break;
      
    case 'bayarea.citygroups.org':
      $vars['sub_site_name'] = t('San Francisco Bay Area');
      break;
      
    case 'staging.citygroups.org':
      $vars['sub_site_name'] = t('Staging');
      break;
      
    default:
      $vars['sub_site_name'] = t('Development');
      break;
  }

  // Remove breadcrumbs if disabled
  if (theme_get_setting('breadcrumb_display') == 0) {
    $vars['breadcrumb'] = '';
  }
}


/**
 * Node preprocessing
 */
function citygroups_preprocess_node(&$vars) {
  // dpm($vars); not working, use this krumo call instead to see the node object.
/*   var_dump(krumo($vars)); */

  // Add to array of handy node classes
  $vars['classes_array'][] = $vars['zebra'];                              // Node is odd or even
  $vars['classes_array'][] = (!$vars['teaser']) ? 'full-node grid_16 alpha' : '';       // Node is teaser or full-node
  
  // Add preprocess functions for all node types.
  $function = __FUNCTION__ . '_' . $vars['node']->type;
  if (function_exists($function)) {
    $function($vars);
  }

/*
  // Node top, bottom & sidebar can't be set with context, unfortunately, until we can figure out
  // how to access blocks set by context. Context seems to override the entire block system...
  // So for now, node regions should only be set in preprocessing
  // functions - to be used for certain fields and the like.*/

  $vars['node_top'] = '';
  $vars['node_bottom'] = '';
  $vars['node_sidebar'] = '';

  // Set margin in grid system for node to flush
  $vars['node_content_width'] = 'alpha';
}


/**
 * Preprocessing function for node types.
 */
function citygroups_preprocess_node_community_group(&$vars) {
  // Load the menu and put it in the preface area.
  // We need to do this here because context does not work with GET paramaters 
  // and we are setting the theme with ?section=blockwatch for sub-sections.

  // Create content variables for this node type.
  
  // Set the author to the last editor of the last revision.
  // @TODO Hide submitted on everything except node page, or else maybe shorten it.

  if($vars['logged_in']) {
    // @TODO set to be more Drupally.
    
    $vars['edit'] .=  t("Is this information incorrect? ") . '<a href="/node/' . $vars['node']->nid . '/edit' . '">' . t("Edit it.") . '</a>';
  }
  else {

    $vars['edit'] .=  t("Is this information incorrect? ") . '<a href="/user?destination=' . 'node/' . $vars['node']->nid . '/edit' . '">' . t("Sign in to edit.") . '</a>';
  }


/*  if(($vars['teaser'] == FALSE) && ($vars['view_mode'] != 'search_result')) {
    $vars['content']['links']['share']['#links']['share']['title'] = datawiki_node_share($vars);
    $vars['content']['links']['share']['#links']['share']['html'] = TRUE;
  }*/
  
  
}
