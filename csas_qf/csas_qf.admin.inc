<?php

function csas_qf_admin_config_form() {
  $form = array();
  $opt_rls = array();
  $sel = db_select('role','r')->fields('r');
  $res = $sel->execute()->fetchAll();
  foreach($res as $rls){
    $opt_rls[$rls->rid] = $rls->name;
  }
  $form['csas_qf_mls'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Sent to roles'),
    '#options' => $opt_rls,
    '#default_value' => variable_get('csas_qf_mls', array()),
  );
  return system_settings_form($form);
}