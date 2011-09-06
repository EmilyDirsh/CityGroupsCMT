<?php

/**
 * Implementation of hook_help().
 */
function cmt_help($section) {
  switch ($section) {
    case 'admin/content/cmt':
      return '<p>'.t('Community-managed vocabularies are listed below.  To add one, <a href="@taxonomy-add-vocab">make a new vocabulary</a> or <a href="@taxonomy-admin">edit an existing vocabulary</a> and select an initial threshold under the "Community management" option.', array('@taxonomy-admin' => url('admin/content/taxonomy'), '@taxonomy-add-vocab' => url('admin/content/taxonomy/add/vocabulary'))).'</p>';
    case 'admin/content/cmt/settings':
      return '<p>'.t('Edit system-wide settings for Community-managed Taxonomy.').'</p>';
  }
}

/**
 * List and manage vocabularies.
 */
function cmt_overview_vocabularies() {
  $vocabularies = cmt_get_vocabularies();
  $rows = array();
  foreach ($vocabularies as $vocabulary) {
    $types = array();
    foreach ($vocabulary->nodes as $type) {
      $node_type = node_get_types('name', $type);
      $types[] = $node_type ? $node_type : $type;
    }
    $rows[] = array('name' => check_plain($vocabulary->name),
      'type' => implode(', ', $types),
      'cmt_edit' => l(t('edit vocabulary community-managed settings'), "admin/content/cmt/edit/vocabulary/$vocabulary->vid"),
      'edit' => l(t('edit other vocabulary settings'), "admin/content/taxonomy/edit/vocabulary/$vocabulary->vid"),
      // 'list' => l(t('list terms'), "admin/content/taxonomy/$vocabulary->vid"),
      // 'add' => l(t('add terms'), "admin/content/taxonomy/$vocabulary->vid/add/term")
    );
  }
  if (empty($rows)) {
    $rows[] = array(array('data' => t('No categories are community-managed.'), 'colspan' => '4'));
  }
  $header = array(t('Name'), t('Type'), array('data' => t('Operations'), 'colspan' => '2'));
  return theme('table', $header, $rows, array('id' => 'taxonomy'));
}

/**
 * Display form for adding and editing vocabularies' community-managed options.
 */
function cmt_vocabulary_form($edit = array()) {
  $form['info'] = array('#type' => 'markup',
    '#value' => '<div>' . t('This administration page is to set options for the community-managed features of this vocabulary, <em>@name</em>.  Edit other aspects of this vocabulary at its <a href="@taxonomy-admin">taxonomy administration page</a>.', array('@taxonomy-admin' => url('admin/content/taxonomy/edit/vocabulary/' . $edit['vid']), '@name' => $edit['name'])) . '</div>',
  );
  $form['cmt_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Community managed'),
    '#default_value' => $edit['cmt_enabled'],
    '#description' => t('Unchecking this box enables you to temporarily disable community managing of this vocabulary without losing stored votes.'),
  );
  $form['thresholds'] = array(
    '#type' => 'fieldset',
    '#title' => t('Thresholds'),
    '#description' => t('Set voting threshold, including to one vote (no threshold).  The lower the threshold setting the more quickly an action takes place based on community input.  You can also disable community-managing capabilities entirely for each aspect of a vocabulary.  Threshold numbers go high because they can, but sticking to low numbers - in fact, the defaults - is recommended unless you have a huge number of active users.  No thresholds can work fine, the default threshold of 2 votes helps keep changes from occurring by accident.  Changing thresholds after the vocabulary is in use may lead to unexpected results.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['threshold_options'] = array(
    '#type' => 'value',
    '#value' => array(
      '0' => t('Disable community management'),
      '1' => t('No threshold (1 vote)'),
      '2' => t('2 votes'),
      '3' => t('3 votes'),
      '4' => t('4 votes'),
      '5' => t('5 votes'),
      '6' => t('6 votes'),
      '7' => t('7 votes'),
      '8' => t('8 votes'),
      '9' => t('9 votes'),
      '10' => t('10 votes'),
      '11' => t('11 votes'),
      '12' => t('12 votes'),
      '13' => t('13 votes'),
      '14' => t('14 votes'),
      '15' => t('15 votes'),
      '16' => t('16 votes'),
      '17' => t('17 votes'),
      '18' => t('18 votes'),
      '19' => t('19 votes'),
      '20' => t('20 votes'),
      '21' => t('21 votes'),
      '22' => t('22 votes'),
      '23' => t('23 votes'),
      '24' => t('24 votes'),
      '25' => t('25 votes'),
      '30' => t('30 votes'),
      '35' => t('35 votes'),
      '40' => t('40 votes'),
      '45' => t('45 votes'),
      '50' => t('50 votes'),
      '55' => t('55 votes'),
      '60' => t('60 votes'),
      '65' => t('65 votes'),
      '70' => t('70 votes'),
      '75' => t('75 votes'),
      '80' => t('80 votes'),
      '90' => t('90 votes'),
      '100' => t('100 votes'),
      '110' => t('110 votes'),
      '120' => t('120 votes'),
      '130' => t('130 votes'),      
      '140' => t('140 votes'),
      '150' => t('150 votes'),
      '160' => t('160 votes'),      
      '170' => t('170 votes'),      
      '180' => t('180 votes'),
      '190' => t('190 votes'),
      '200' => t('200 votes'),
    ),
  );
  $form['thresholds']['cmt_description_th'] = array(
    '#type' => 'select',  // for dropdown
    '#title' => t('Description'),
    '#options' => $form['threshold_options']['#value'],
    '#default_value' => $edit['cmt_description_th'],
    '#description' => t('Votes needed for the first user-chosen description to be used.'),
  );
  $form['thresholds']['cmt_weight_th'] = array(
    '#type' => 'select',
    '#title' => t('Weight'),
    '#options' => $form['threshold_options']['#value'],
    '#default_value' => $edit['cmt_weight_th'],
    '#description' => t('Votes needed for the first user-chosen weight to be used.'),
  );
  $form['thresholds']['cmt_name_th'] = array(
    '#type' => 'select',
    '#title' => t('Names'),
    '#options' => $form['threshold_options']['#value'],
    '#default_value' => $edit['cmt_name_th'],
    '#description' => t('Votes needed for the first user-chosen name or any user-chosen synonym to be used.'),
  );
  $form['thresholds']['cmt_hierarchy_th'] = array(
    '#type' => 'select',
    '#title' => t('Positions'),
    '#options' => $form['threshold_options']['#value'],
    '#default_value' => $edit['cmt_hierarchy_th'],
    '#description' => t('Votes needed for any user-chosen term position (also called arrangement, hierarchy, structure, categorization) to be used.'),
  );
   $form['thresholds']['cmt_node_th'] = array(
    '#type' => 'select',
    '#title' => t('Creating terms'),
    '#options' => $form['threshold_options']['#value'],
    '#default_value' => $edit['cmt_node_th'],
    '#description' => t('Votes needed for any user-chosen term to be created and attached to a node (in short, the threshold for tagging).'),
  );
 $form['thresholds']['cmt_merge_th'] = array(
    '#type' => 'select',
    '#title' => t('Merge'),
    '#options' => $form['threshold_options']['#value'],
    '#default_value' => $edit['cmt_merge_th'],
    '#description' => t('Votes needed for any user-chosen merging of terms to take effect.'),
  );
  $form['thresholds']['cmt_related_th'] = array(
    '#type' => 'select',
    '#title' => t('Related terms'),
    '#options' => $form['threshold_options']['#value'],
    '#default_value' => $edit['cmt_related_th'],
    '#description' => t('Votes <em>for merging</em> needed for terms to be considered related terms (that is, term relations are derived from users\' term merge recommendations).  Related terms must be enabled for this vocabulary.'), // (unless I can do it programatically)
  );

  // it should not be possible to edit this form without a vid present
  $form['vid'] = array('#type' => 'value', '#value' => $edit['vid']);
  $form['module'] = array('#type' => 'value', '#value' => $edit['module']);
  $new = 'update';  // not new
  if ($edit['cmt_enabled']===NULL) $new = 'insert';  // somehow, new
  $form['new'] = array('#type' => 'value', '#value' => $new);
  $form['name'] = array('#type' => 'value', '#value' => $edit['name']);

  $form['submit'] = array('#type' => 'submit', '#value' => t('Submit'));

  return $form;
}

/**
 * Accept the form submission for a vocabulary and save the results.
 */
function cmt_vocabulary_form_submit($form_id, $form_values) {
  switch (cmt_save_vocabulary($form_values, $form_values['new'])) {
    // this should never happen here-- this only edits existing vocabs right now
    // however, since I screwed up the uninstall (it didn't change vocab names back)
    // I made this so I could just make CMT vocabs with no entries a new vocab
    case SAVED_NEW:
      drupal_set_message(t('Made vocabulary %name community-managed.', array('%name' => $form_values['name'])));
      break;
    case SAVED_UPDATED:
      drupal_set_message(t('Updated community-managed options for vocabulary %name.', array('%name' => $form_values['name'])));
      break;
  }
  return 'admin/content/cmt';
}

function cmt_save_vocabulary($edit, $op = 'insert') {
  switch ($op) {
    case 'update':
      if (db_query("UPDATE {cmt_vocabulary} c SET c.cmt_enabled = %d, c.cmt_description_th = %d, c.cmt_weight_th = %d, c.cmt_name_th = %d, c.cmt_hierarchy_th = %d, c.cmt_merge_th = %d, c.cmt_node_th = %d, c.cmt_related_th = %d WHERE c.vid = %d", $edit['cmt_enabled'], $edit['cmt_description_th'], $edit['cmt_weight_th'], $edit['cmt_name_th'], $edit['cmt_hierarchy_th'], $edit['cmt_merge_th'], $edit['cmt_node_th'], $edit['cmt_related_th'], $edit['vid'])) {
        return SAVED_UPDATED;     
      }
      break;
    case 'insert':  
      // $edit['vid'] should be available from taxonomy_save_vocabulary, which had it by reference
      if (db_query("INSERT INTO {cmt_vocabulary} (vid, cmt_enabled, cmt_description_th, cmt_weight_th, cmt_name_th, cmt_hierarchy_th, cmt_merge_th, cmt_node_th, cmt_related_th) VALUES (%d, %d, %d, %d, %d, %d, %d, %d, %d)", $edit['vid'], $edit['cmt_enabled'], $edit['cmt_description_th'], $edit['cmt_weight_th'], $edit['cmt_name_th'], $edit['cmt_hierarchy_th'], $edit['cmt_merge_th'], $edit['cmt_node_th'], $edit['cmt_related_th'])) {
        return SAVED_NEW;
      }
  }
}

/**
 * Delete a vocabulary.
 *
 * @param $vid
 *   A vocabulary ID.
 * @return
 *   Constant indicating items were deleted.
 */
function _cmt_del_vocabulary($vid) {
  db_query('DELETE FROM {cmt_vocabulary} WHERE vid = %d', $vid);
  $result = db_query('SELECT tid FROM {cmt_term_vocab} WHERE vid = %d', $vid);
  while ($term = db_fetch_object($result)) {
    // core taxonomy uses taxonomy_del_term but CMT don't delete unless whole vocab killed
    // can't this be done in one pretty query?  Why doesn't Drupal core do that?
    db_query('DELETE FROM {cmt_term_data} WHERE tid = %d', $tid);
    db_query('DELETE FROM {cmt_term_description} WHERE tid = %d', $tid);
    db_query('DELETE FROM {cmt_term_weight} WHERE tid = %d', $tid);
    db_query('DELETE FROM {cmt_term_name} WHERE tid = %d', $tid);
    db_query('DELETE FROM {cmt_term_hierarchy} WHERE tid = %d', $tid);
    db_query('DELETE FROM {cmt_term_merge} WHERE tid1 = %d OR tid2 = %d', $tid, $tid);
    db_query('DELETE FROM {cmt_term_node} WHERE tid = %d', $tid);
    db_query('DELETE FROM {cmt_term_vocab} WHERE tid = %d', $tid);
  }
  return SAVED_DELETED;
}

/**
 * Page to edit the community-management settings for a vocabulary.
 */
function cmt_admin_vocabulary_edit($vid = NULL) {
  if (!is_numeric($vid)) {
    drupal_set_message("That's not a number!", 'error');
    return;
  }
  // deleting vocabularies is handled by taxonomy.module's admin pages, not here
  // same with creating.  So if there's no vid, don't show the form
  // it better be one of ours, too
  if (cmt_is_vid_cmt($vid)) {
    $vocabulary = (array)taxonomy_get_vocabulary($vid);
    $cmt_vocabulary = (array)cmt_get_vocabulary($vid);  // get the CMT info for this vocab
    $vocabulary = array_merge($vocabulary, $cmt_vocabulary);
    return drupal_get_form('cmt_vocabulary_form', $vocabulary);
  }
  return drupal_not_found();
}


/**
 * Configures Community Managed Taxonomy site-wide options.
 */
function cmt_settings_form() {
  $form = array();
  $form['information'] = array(
    '#type' => 'markup',
    '#title' => t('Site-wide settings for Community Managed Taxonomy'),
    '#description' => t('Terms added or modified through the usual administrative interface (rather than through community managed taxonomy\'s collaborative interface) are padded up to the minimum threshold or the number of votes needed to have it take effect.'),
  );
  $form['general'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('General settings'),
    '#collapsible'   => TRUE,
    '#collapsed'     => FALSE,
  );
  
  $form['general']['teasers'] = array('#type' => 'checkboxes',
    '#title'         => t('Term management on teasers'),
    '#default_value' => _cmt_get_teaser_types(),
    '#options'       => array_map('check_plain', cmt_node_types('names')),
    '#description'   => t('Content types for which you want to display the CMT term management form on <strong>teasers</strong>.  Because this form can become quite large, this is generally not recommended.  <em>Content types which are not associated with a community-managed vocabulary are not listed.</em>'),
  );
  $form['buttons']['submit'] = array('#type' => 'submit', '#value' => t('Save configuration') );
  $form['buttons']['reset'] = array('#type' => 'submit', '#value' => t('Reset to defaults') );
  return $form;
}

function _cmt_get_teaser_types() {
  $types = cmt_node_types();
  $options = array();
  foreach ($types AS $type) {
    $options[$type] = variable_get('cmt_teaser_' . $type, 0) ? $type : 0;
  }
  return $options;
}

/**
 * Execute the cmt_settings_form.
 */
function cmt_settings_form_submit($form_id, $form_values) {
  $op = isset($form_values['op']) ? $form_values['op'] : '';
  $types = $form_values['teasers'];
  foreach ($types AS $type => $val) {
    $val = $val ? 1 : 0;
    variable_set('cmt_teaser_' . $type, $val);
  }
  return;
}

/**
 * Catch our additions to the node_type_form (custom submit call)
 */
function cmt_node_type_form_submit($form_id, &$form) {
  variable_set('cmt_teaser_' . $form['#node_type']->type, $form['cmt_teaser']['#value']);
  // would having 'return' here be best practice?
}

/**
 * Implementation of hook_user
 * 
 * Delete user CMT votes and recalculate results.
 *
 */
function cmt_user($op, $edit, $account, $category) {
  if ($op == 'delete') {
  /* I would have liked to delete votes from a user and recalculate results when a user is deleted.  It's not a big deal but votingapi's lack of an easy way to do this surprises me.
  All vote deleting by user AND vote recalculating functions require you to also provide the content ID, which quite defeats the point.  I'm happy to delete a user content_type at a time, but I can't believe I have to run a select on users and content_ids first, or write my own way of tracking what content_ids I delete users from, in order to keep the tally of results accurate.
  When I do so I'll want it to tell me when I'm deleting the only vote for a content_id so I can delete its row in my cmt_whatever_type table as well
  */
  //  $votingapi_cache = votingapi_unset_vote('cmt_term_description', $content_id, $uid = NULL)
  //  cmt_push($content_type, $content_id, $votingapi_cache)
  }
}