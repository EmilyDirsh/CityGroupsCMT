<?php
/**
 * @file 
 *
 * Default thresholds for community-managed taxonomy (cmt.module)
 *
 * Used in *first* cmt_save_vocabulary
 * All later retrieved from the database
 * Zero means this metric is disabled in community managed taxonomy for this vocabulary.
 * It cannot be voted on.
 * One means no threshold, one vote does it.  Two means a threshold of two votes for an action to take place.
 */
 
// 0 = disabled on the admin/content/taxonomy/add page

$related = 0;
switch ($array['cmt_vocabulary']['#value']) {
	case 1:  // no thresholds (aka low)
		$array['cmt_description_th'] = 1;
		$array['cmt_weight_th'] = 1;
		$array['cmt_name_th'] = 1;
		$array['cmt_hierarchy_th'] = 1;
		$array['cmt_merge_th'] = 1;
		$array['cmt_node_th'] = 1;
		$array['cmt_related_th'] = 0;
		break;

	case 3:  // default with related terms derived
		$related = 1;
	case 2:  // default
		$array['cmt_description_th'] = 2;
		$array['cmt_weight_th'] = 2;
		$array['cmt_name_th'] = 2;
		$array['cmt_hierarchy_th'] = 2;
		$array['cmt_merge_th'] = 2;
		$array['cmt_node_th'] = 2;
		$array['cmt_related_th'] = $related;
		unset($related);
		break;

	case 4: // high thresholds with related terms derived
		$array['cmt_description_th'] = 4;
		$array['cmt_weight_th'] = 4;
		$array['cmt_name_th'] = 4;
		$array['cmt_hierarchy_th'] = 3;
		$array['cmt_merge_th'] = 5;
		$array['cmt_node_th'] = 5;
		$array['cmt_related_th'] = 3;
		break;
}