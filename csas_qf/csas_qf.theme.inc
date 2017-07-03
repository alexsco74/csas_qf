<?php

/**
 * Theme function csas_qf
 */
function theme_csas_qf_tme($vars) {
  $var_frm = drupal_get_form('csas_qf_form');
  $opt = array(
    'mde' => 'min',
    'link_title' => 'Обратный звонок',
    'title' => 'Обратный звонок',
    'content' => drupal_render($var_frm),
    'class' => 'csas-qf'
  );

  $build = array(
    'view' => array(
      '#theme' => 'csas_modal_view',
      '#opt' => $opt,
    )
  );
  return drupal_render($build);
}