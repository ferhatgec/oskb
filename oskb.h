// MIT License
//
// Copyright (c) 2023 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef OSKB_H
#define OSKB_H

#include <QPushButton>
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class oskb; }
QT_END_NAMESPACE

class oskb : public QMainWindow
{
    Q_OBJECT

public:
    oskb(QWidget* parent = nullptr);
    ~oskb();

    void setup(QPushButton*& button)
        noexcept;

    void push(unsigned char keycode)
        noexcept;

    void special_push(unsigned char keycode)
        noexcept;

    void caps_lock()
        noexcept;

private slots:
    void on_q_clicked();

    void on_g_clicked();

    void on_w_clicked();

    void on_e_clicked();

    void on_r_clicked();

    void on_t_clicked();

    void on_y_clicked();

    void on_u_clicked();

    void on_i_clicked();

    void on_o_clicked();

    void on_p_clicked();

    void on_a_clicked();

    void on_s_clicked();

    void on_d_clicked();

    void on_f_clicked();

    void on_h_clicked();

    void on_j_clicked();

    void on_k_clicked();

    void on_l_clicked();

    void on_z_clicked();

    void on_x_clicked();

    void on_c_clicked();

    void on_v_clicked();

    void on_b_clicked();

    void on_n_clicked();

    void on_m_clicked();

    void on_backspace_clicked();

    void on_enter_clicked();

    void on_capslock_clicked();

    void on_space_clicked();

    void on_super_2_clicked();

    void on_one_clicked();

    void on_two_clicked();

    void on_three_clicked();

    void on_four_clicked();

    void on_five_clicked();

    void on_six_clicked();

    void on_seven_clicked();

    void on_eight_clicked();

    void on_nine_clicked();

    void on_zero_clicked();

    void on_backtick_clicked();

    void on_exclamation_clicked();

    void on_plus_clicked();

    void on_minus_clicked();

    void on_percent_clicked();

    void on_quotation_clicked();

    void on_asterisk_clicked();

    void on_caret_clicked();

    void on_prl_clicked();

    void on_prr_clicked();

    void on_sql_clicked();

    void on_sqr_clicked();

    void on_curlyl_clicked();

    void on_curlyr_clicked();

    void on_ltr_clicked();

    void on_ltl_clicked();

    void on_sem_clicked();

    void on_colon_clicked();

    void on_comma_clicked();

    void on_dot_clicked();

    void on_slash_clicked();

    void on_vertical_bar_clicked();

    void on_at_clicked();

    void on_underscore_clicked();

    void on_dollar_clicked();

    void on_hashtag_clicked();

    void on_equals_clicked();

    void on_gech_key_clicked();

    void on_reverse_slash_clicked();

private:
    Ui::oskb* ui;
};
#endif // OSKB_H
