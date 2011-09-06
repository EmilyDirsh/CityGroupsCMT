
/**
 * @file  js support for the set of forms displayed beneath nodes for community managing terms
 */

$(document).ready(function(){
  $('.cmt-terms-node-view .term').show(); 
  $('.cmt-terms-node-view h4 a').click(function() {
    $(this).parent().next(".term").slideToggle('fast');
    return false;
  });
});