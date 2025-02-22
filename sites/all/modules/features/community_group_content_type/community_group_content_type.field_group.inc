<?php
/**
 * @file
 * community_group_content_type.field_group.inc
 */

/**
 * Implementation of hook_field_group_info().
 */
function community_group_content_type_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic|node|community_group|form';
  $field_group->group_name = 'group_basic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_contact',
      1 => 'field_description',
      2 => 'field_email',
      3 => 'field_url',
      4 => 'field_url_calendar',
      5 => 'title',
      6 => 'group_information',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_basic|node|community_group|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categories_advanced|node|community_group|default';
  $field_group->group_name = 'group_categories_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_categories';
  $field_group->data = array(
    'label' => 'More',
    'weight' => '29',
    'children' => array(
      0 => 'field_demographic',
      1 => 'field_term_civic_taxonomy',
      2 => 'field_type_community',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_categories_advanced|node|community_group|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categories_advanced|node|community_group|form';
  $field_group->group_name = 'group_categories_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_categories';
  $field_group->data = array(
    'label' => 'More',
    'weight' => '6',
    'children' => array(
      0 => 'field_demographic',
      1 => 'field_term_civic_taxonomy',
      2 => 'field_type_community',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'More',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_categories_advanced|node|community_group|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categories|node|community_group|default';
  $field_group->group_name = 'group_categories';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Categories',
    'weight' => '1',
    'children' => array(
      0 => 'field_activity',
      1 => 'field_audience_size',
      2 => 'field_categories',
      3 => 'field_ownership',
      4 => 'field_type_group',
      5 => 'group_categories_advanced',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Categories',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_categories|node|community_group|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categories|node|community_group|form';
  $field_group->group_name = 'group_categories';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Categories',
    'weight' => '2',
    'children' => array(
      0 => 'field_activity',
      1 => 'field_audience_size',
      2 => 'field_categories',
      3 => 'field_ownership',
      4 => 'field_type_group',
      5 => 'group_categories_advanced',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_categories|node|community_group|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_geographic|node|community_group|form';
  $field_group->group_name = 'group_geographic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Map this Group',
    'weight' => '3',
    'children' => array(
      0 => 'field_location',
      1 => 'field_location_description',
      2 => 'field_neighborhood',
      3 => 'field_zipcode',
      4 => 'group_location',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_geographic|node|community_group|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_group|node|community_group|default';
  $field_group->group_name = 'group_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_location';
  $field_group->data = array(
    'label' => 'More',
    'weight' => '9',
    'children' => array(
      0 => 'field_address',
      1 => 'field_area_code',
      2 => 'field_city',
      3 => 'field_county',
      4 => 'field_district',
      5 => 'field_region',
      6 => 'field_state',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'More',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_group|node|community_group|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_information|node|community_group|form';
  $field_group->group_name = 'group_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_basic';
  $field_group->data = array(
    'label' => 'More Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_notes',
      1 => 'field_source',
      2 => 'field_url_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_information|node|community_group|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location|node|community_group|default';
  $field_group->group_name = 'group_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '2',
    'children' => array(
      0 => 'field_location',
      1 => 'field_location_description',
      2 => 'field_neighborhood',
      3 => 'field_zipcode',
      4 => 'group_group',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Location',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_location|node|community_group|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location|node|community_group|form';
  $field_group->group_name = 'group_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_geographic';
  $field_group->data = array(
    'label' => 'More',
    'weight' => '20',
    'children' => array(
      0 => 'field_address',
      1 => 'field_area_code',
      2 => 'field_city',
      3 => 'field_county',
      4 => 'field_district',
      5 => 'field_location_geocode',
      6 => 'field_region',
      7 => 'field_state',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'More',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_location|node|community_group|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|node|community_group|default';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_overview';
  $field_group->data = array(
    'label' => 'More',
    'weight' => '24',
    'children' => array(
      0 => 'field_notes',
      1 => 'field_source',
      2 => 'field_url_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'More',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_metadata|node|community_group|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_overview|node|community_group|default';
  $field_group->group_name = 'group_overview';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_contact',
      1 => 'field_description',
      2 => 'field_url',
      3 => 'field_url_calendar',
      4 => 'group_metadata',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_overview|node|community_group|default'] = $field_group;

  return $export;
}
