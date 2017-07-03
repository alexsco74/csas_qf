(function ($) {
    var waitTag = jQuery('<div class="sty-ldr"></div>');
    function csasQfSmt(formIn) {
        var eS = true;
        if (formIn.height != 0) {
            $('.required', formIn).each(function () {
                if ($(this).val() == '') {
                    eS = false;
                    $(this).parent().addClass('sty-form-error');

                } else {
                    $(this).parent().removeClass('sty-form-error');

                }
            });
        } else {
            eS = false;
        }
        return eS;
    }

    Drupal.behaviors.csasQf = {
        attach: function (context, settings) {
            $('.css-qf-frm', context).once('csas-qf-frm', function () {
                var tF = $(this);
                $('.required', tF).bind('change', function () {
                    csasQfSmt(tF);
                });
                $('.form-submit', tF).bind('click', function () {
                    if (!csasQfSmt(tF)) {
                        return false;
                    } else {
                        tF.addClass('sty-ajx-lad-prs').append(waitTag);
                        tF.submit();
                        $(this).attr('disabled', true);
                    }
                });
            });
        }
    };
})(jQuery);



