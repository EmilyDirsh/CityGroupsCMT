<?php
/**
 * @file
 * community_group_upload_csv.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function community_group_upload_csv_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_community_group_feed_upload_csv';
  $strongarm->value = 0;
  $export['comment_anonymous_community_group_feed_upload_csv'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_community_group_feed_upload_csv';
  $strongarm->value = '2';
  $export['comment_community_group_feed_upload_csv'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_community_group_feed_upload_csv';
  $strongarm->value = 1;
  $export['comment_default_mode_community_group_feed_upload_csv'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_community_group_feed_upload_csv';
  $strongarm->value = '50';
  $export['comment_default_per_page_community_group_feed_upload_csv'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_community_group_feed_upload_csv';
  $strongarm->value = 1;
  $export['comment_form_location_community_group_feed_upload_csv'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_community_group_feed_upload_csv';
  $strongarm->value = '1';
  $export['comment_preview_community_group_feed_upload_csv'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_community_group_feed_upload_csv';
  $strongarm->value = 1;
  $export['comment_subject_field_community_group_feed_upload_csv'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_community_group_feed_upload_csv';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_community_group_feed_upload_csv'] = $strongarm;

  return $export;
}
