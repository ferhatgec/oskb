// MIT License
//
// Copyright (c) 2023 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#include "oskb.h"
#include "./ui_oskb.h"

#include <QTimer>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
#define XK_PUBLISHING
#include <X11/keysym.h>
#include <X11/XKBlib.h>

Display* dis = XOpenDisplay(NULL);
unsigned state;

constexpr unsigned oskb_delay = 300;
constexpr unsigned oskb_interval = oskb_delay / 10;

const unsigned char OSKB_Q = XKeysymToKeycode(dis, XStringToKeysym("q"));
const unsigned char OSKB_W = XKeysymToKeycode(dis, XStringToKeysym("w"));
const unsigned char OSKB_E = XKeysymToKeycode(dis, XStringToKeysym("e"));
const unsigned char OSKB_R = XKeysymToKeycode(dis, XStringToKeysym("r"));
const unsigned char OSKB_T = XKeysymToKeycode(dis, XStringToKeysym("t"));
const unsigned char OSKB_Y = XKeysymToKeycode(dis, XStringToKeysym("y"));
const unsigned char OSKB_U = XKeysymToKeycode(dis, XStringToKeysym("u"));
const unsigned char OSKB_I = XKeysymToKeycode(dis, XStringToKeysym("i"));
const unsigned char OSKB_O = XKeysymToKeycode(dis, XStringToKeysym("o"));
const unsigned char OSKB_P = XKeysymToKeycode(dis, XStringToKeysym("p"));

const unsigned char OSKB_A = XKeysymToKeycode(dis, XStringToKeysym("a"));
const unsigned char OSKB_S = XKeysymToKeycode(dis, XStringToKeysym("s"));
const unsigned char OSKB_D = XKeysymToKeycode(dis, XStringToKeysym("d"));
const unsigned char OSKB_F = XKeysymToKeycode(dis, XStringToKeysym("f"));
const unsigned char OSKB_G = XKeysymToKeycode(dis, XStringToKeysym("g"));
const unsigned char _OSKB_H= XKeysymToKeycode(dis, XStringToKeysym("h"));
const unsigned char OSKB_J = XKeysymToKeycode(dis, XStringToKeysym("j"));
const unsigned char OSKB_K = XKeysymToKeycode(dis, XStringToKeysym("k"));
const unsigned char OSKB_L = XKeysymToKeycode(dis, XStringToKeysym("l"));

const unsigned char OSKB_Z = XKeysymToKeycode(dis, XStringToKeysym("z"));
const unsigned char OSKB_X = XKeysymToKeycode(dis, XStringToKeysym("x"));
const unsigned char OSKB_C = XKeysymToKeycode(dis, XStringToKeysym("c"));
const unsigned char OSKB_V = XKeysymToKeycode(dis, XStringToKeysym("v"));
const unsigned char OSKB_B = XKeysymToKeycode(dis, XStringToKeysym("b"));
const unsigned char OSKB_N = XKeysymToKeycode(dis, XStringToKeysym("n"));
const unsigned char OSKB_M = XKeysymToKeycode(dis, XStringToKeysym("m"));

const unsigned char OSKB_BKSP = XKeysymToKeycode(dis, XK_BackSpace);
const unsigned char OSKB_ENTER = XKeysymToKeycode(dis, XK_Return);
const unsigned char OSKB_CAPS_LOCK = XKeysymToKeycode(dis, XK_Caps_Lock);
const unsigned char OSKB_SPACE = XKeysymToKeycode(dis, XK_space);
const unsigned char OSKB_SUPER_L = XKeysymToKeycode(dis, XK_Super_L);

const unsigned char OSKB_1 = XKeysymToKeycode(dis, XStringToKeysym("1"));
const unsigned char OSKB_2 = XKeysymToKeycode(dis, XStringToKeysym("2"));
const unsigned char OSKB_3 = XKeysymToKeycode(dis, XStringToKeysym("3"));
const unsigned char OSKB_4 = XKeysymToKeycode(dis, XStringToKeysym("4"));
const unsigned char OSKB_5 = XKeysymToKeycode(dis, XStringToKeysym("5"));
const unsigned char OSKB_6 = XKeysymToKeycode(dis, XStringToKeysym("6"));
const unsigned char OSKB_7 = XKeysymToKeycode(dis, XStringToKeysym("7"));
const unsigned char OSKB_8 = XKeysymToKeycode(dis, XStringToKeysym("8"));
const unsigned char OSKB_9 = XKeysymToKeycode(dis, XStringToKeysym("9"));
const unsigned char OSKB_0 = XKeysymToKeycode(dis, XStringToKeysym("0"));

const unsigned char OSKB_BT = XKeysymToKeycode(dis, XK_quoteleft);
const unsigned char OSKB_EX = 10;
const unsigned char OSKB_PL = XKeysymToKeycode(dis, XK_KP_Add);
const unsigned char OSKB_MIN = XKeysymToKeycode(dis, XK_minus);
const unsigned char OSKB_PC = 14;
const unsigned char OSKB_QUO = 48;
const unsigned char OSKB_AST = 17;
const unsigned char OSKB_CR = 15;
const unsigned char OSKB_PRL = XKeysymToKeycode(dis, XK_parenleft);
const unsigned char OSKB_PRR = XKeysymToKeycode(dis, XK_parenright);

const unsigned char OSKB_SQL = XKeysymToKeycode(dis, XK_bracketleft);
const unsigned char OSKB_SQR = XKeysymToKeycode(dis, XK_bracketright);
const unsigned char OSKB_CRL = 34;
const unsigned char OSKB_CRR = 35;
const unsigned char OSKB_LTR = 60;
const unsigned char OSKB_LTL = XKeysymToKeycode(dis, XK_less);
const unsigned char OSKB_SEM = XKeysymToKeycode(dis, XK_semicolon);
const unsigned char OSKB_COL = 47;
const unsigned char OSKB_COM = XKeysymToKeycode(dis, XK_comma);
const unsigned char OSKB_DOT = XKeysymToKeycode(dis, XK_period);

const unsigned char OSKB_SL = XKeysymToKeycode(dis, XK_KP_Divide);
const unsigned char OSKB_RVSL = 51;
const unsigned char OSKB_VB = 51;
const unsigned char OSKB_USD = 13;
const unsigned char OSKB_HT = 12;
const unsigned char OSKB_AT = 11;
const unsigned char OSKB_US = 20;
const unsigned char OSKB_EQ = XKeysymToKeycode(dis, XK_KP_Equal);

oskb::oskb(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::oskb)
{
    ui->setupUi(this);

    this->caps_lock();

    ui->q->setText("q");
    ui->w->setText("w");
    ui->e->setText("e");
    ui->r->setText("r");
    ui->t->setText("t");
    ui->y->setText("y");
    ui->u->setText("u");
    ui->i->setText("i");
    ui->o->setText("o");
    ui->p->setText("p");

    ui->a->setText("a");
    ui->s->setText("s");
    ui->d->setText("d");
    ui->f->setText("f");
    ui->g->setText("g");
    ui->h->setText("h");
    ui->j->setText("j");
    ui->k->setText("k");
    ui->l->setText("l");

    ui->z->setText("z");
    ui->x->setText("x");
    ui->c->setText("c");
    ui->v->setText("v");
    ui->b->setText("b");
    ui->n->setText("n");
    ui->m->setText("m");

    this->setup(ui->q);
    this->setup(ui->w);

    this->setup(ui->w);
    this->setup(ui->e);
    this->setup(ui->r);
    this->setup(ui->t);
    this->setup(ui->y);
    this->setup(ui->u);
    this->setup(ui->i);
    this->setup(ui->o);
    this->setup(ui->p);

    this->setup(ui->a);
    this->setup(ui->s);
    this->setup(ui->d);
    this->setup(ui->f);
    this->setup(ui->g);
    this->setup(ui->h);
    this->setup(ui->j);
    this->setup(ui->k);
    this->setup(ui->l);

    this->setup(ui->z);
    this->setup(ui->x);
    this->setup(ui->c);
    this->setup(ui->v);
    this->setup(ui->b);
    this->setup(ui->n);
    this->setup(ui->m);

    this->setup(ui->backspace);
    this->setup(ui->enter);
    this->setup(ui->capslock);
    this->setup(ui->space);
    this->setup(ui->super_2);

    this->setup(ui->one);
    this->setup(ui->two);
    this->setup(ui->three);
    this->setup(ui->four);
    this->setup(ui->five);
    this->setup(ui->six);
    this->setup(ui->seven);
    this->setup(ui->eight);
    this->setup(ui->nine);
    this->setup(ui->zero);

    this->setup(ui->backtick);
    this->setup(ui->exclamation);
    this->setup(ui->plus);
    this->setup(ui->minus);
    this->setup(ui->percent);
    this->setup(ui->quotation);
    this->setup(ui->asterisk);
    this->setup(ui->caret);
    this->setup(ui->prl);
    this->setup(ui->prr);

    this->setup(ui->sql);
    this->setup(ui->sqr);
    this->setup(ui->curlyl);
    this->setup(ui->curlyr);
    this->setup(ui->ltr);
    this->setup(ui->ltl);
    this->setup(ui->sem);
    this->setup(ui->colon);
    this->setup(ui->comma);
    this->setup(ui->dot);

    this->setup(ui->slash);
    this->setup(ui->reverse_slash);

    this->setup(ui->vertical_bar);
    this->setup(ui->dollar);
    this->setup(ui->hashtag);
    this->setup(ui->at);
    this->setup(ui->underscore);
    this->setup(ui->equals);
    this->setup(ui->gech_key);
}

oskb::~oskb()
{
    XCloseDisplay(dis);
    delete ui;
}

void oskb::setup(QPushButton*& button) noexcept
{
    button->setAutoRepeat(true);
    button->setAutoRepeatDelay(oskb_delay);
    button->setAutoRepeatInterval(oskb_interval);
}

void oskb::push(unsigned char keycode) noexcept
{
    XTestFakeKeyEvent(dis, keycode, True, 1);
    XFlush(dis);
    XTestFakeKeyEvent(dis, keycode, False, 1);
    XFlush(dis);
}

void oskb::special_push(unsigned char keycode) noexcept
{
    XTestFakeKeyEvent(dis, 50, True, 1);
    XFlush(dis);
    XTestFakeKeyEvent(dis, keycode, True, 1);
    XFlush(dis);
    XTestFakeKeyEvent(dis, 50, False, 1);
    XFlush(dis);
    XTestFakeKeyEvent(dis, keycode, False, 1);
    XFlush(dis);
}

void oskb::caps_lock() noexcept {
    if(XkbGetIndicatorState(dis, XkbUseCoreKbd, &state) != Success)
        return;

    if(!(state & 1)) {
        ui->q->setText("Q");
        ui->w->setText("W");
        ui->e->setText("E");
        ui->r->setText("R");
        ui->t->setText("T");
        ui->y->setText("Y");
        ui->u->setText("U");
        ui->i->setText("I");
        ui->o->setText("O");
        ui->p->setText("P");

        ui->a->setText("A");
        ui->s->setText("S");
        ui->d->setText("D");
        ui->f->setText("F");
        ui->g->setText("G");
        ui->h->setText("H");
        ui->j->setText("J");
        ui->k->setText("K");
        ui->l->setText("L");

        ui->z->setText("Z");
        ui->x->setText("X");
        ui->c->setText("C");
        ui->v->setText("V");
        ui->b->setText("B");
        ui->n->setText("N");
        ui->m->setText("M");

        ui->gech_key->setText("GECH KEY");
    } else {
        ui->q->setText("q");
        ui->w->setText("w");
        ui->e->setText("e");
        ui->r->setText("r");
        ui->t->setText("t");
        ui->y->setText("y");
        ui->u->setText("u");
        ui->i->setText("i");
        ui->o->setText("o");
        ui->p->setText("p");

        ui->a->setText("a");
        ui->s->setText("s");
        ui->d->setText("d");
        ui->f->setText("f");
        ui->g->setText("g");
        ui->h->setText("h");
        ui->j->setText("j");
        ui->k->setText("k");
        ui->l->setText("l");

        ui->z->setText("z");
        ui->x->setText("x");
        ui->c->setText("c");
        ui->v->setText("v");
        ui->b->setText("b");
        ui->n->setText("n");
        ui->m->setText("m");

        ui->gech_key->setText("gech key");
    }
}

void oskb::on_q_clicked() { this->push(OSKB_Q); }
void oskb::on_w_clicked() { this->push(OSKB_W); }
void oskb::on_e_clicked() { this->push(OSKB_E); }
void oskb::on_r_clicked() { this->push(OSKB_R); }
void oskb::on_t_clicked() { this->push(OSKB_T); }
void oskb::on_y_clicked() { this->push(OSKB_Y); }
void oskb::on_u_clicked() { this->push(OSKB_U); }
void oskb::on_i_clicked() { this->push(OSKB_I); }
void oskb::on_o_clicked() { this->push(OSKB_O); }
void oskb::on_p_clicked() { this->push(OSKB_P); }
void oskb::on_a_clicked() { this->push(OSKB_A); }
void oskb::on_s_clicked() { this->push(OSKB_S); }
void oskb::on_d_clicked() { this->push(OSKB_D); }
void oskb::on_f_clicked() { this->push(OSKB_F); }
void oskb::on_g_clicked() { this->push(OSKB_G); }
void oskb::on_h_clicked() { this->push(_OSKB_H); }
void oskb::on_j_clicked() { this->push(OSKB_J); }
void oskb::on_k_clicked() { this->push(OSKB_K); }
void oskb::on_l_clicked() { this->push(OSKB_L); }
void oskb::on_z_clicked() { this->push(OSKB_Z); }
void oskb::on_x_clicked() { this->push(OSKB_X); }
void oskb::on_c_clicked() { this->push(OSKB_C); }
void oskb::on_v_clicked() { this->push(OSKB_V); }
void oskb::on_b_clicked() { this->push(OSKB_B); }
void oskb::on_n_clicked() { this->push(OSKB_N); }
void oskb::on_m_clicked() { this->push(OSKB_M); }
void oskb::on_backspace_clicked() { this->push(OSKB_BKSP); }
void oskb::on_enter_clicked() { this->push(OSKB_ENTER); }

void oskb::on_capslock_clicked()
{
    this->caps_lock();
    this->push(OSKB_CAPS_LOCK);
}


void oskb::on_space_clicked() { this->push(OSKB_SPACE); }
void oskb::on_super_2_clicked() { this->push(OSKB_SUPER_L); }
void oskb::on_one_clicked() { this->push(OSKB_1); }
void oskb::on_two_clicked() { this->push(OSKB_2); }
void oskb::on_three_clicked() { this->push(OSKB_3); }
void oskb::on_four_clicked() { this->push(OSKB_4); }
void oskb::on_five_clicked() { this->push(OSKB_5); }
void oskb::on_six_clicked() { this->push(OSKB_6); }
void oskb::on_seven_clicked() { this->push(OSKB_7); }
void oskb::on_eight_clicked() { this->push(OSKB_8); }
void oskb::on_nine_clicked() { this->push(OSKB_9); }
void oskb::on_zero_clicked() { this->push(OSKB_0); }
void oskb::on_backtick_clicked() { this->push(OSKB_BT); }
void oskb::on_exclamation_clicked() { this->special_push(OSKB_EX); }
void oskb::on_plus_clicked() { this->push(OSKB_PL); }
void oskb::on_minus_clicked() { this->push(OSKB_MIN); }
void oskb::on_percent_clicked() { this->special_push(OSKB_PC); }
void oskb::on_quotation_clicked() { this->special_push(OSKB_QUO); }
void oskb::on_asterisk_clicked() { this->special_push(OSKB_AST); }
void oskb::on_caret_clicked() { this->special_push(OSKB_CR); }
void oskb::on_prl_clicked() {this->push(OSKB_PRL); }
void oskb::on_prr_clicked() { this->push(OSKB_PRR);  }
void oskb::on_sql_clicked() { this->push(OSKB_SQL); }
void oskb::on_sqr_clicked() { this->push(OSKB_SQR); }
void oskb::on_curlyl_clicked() { this->special_push(OSKB_CRL); }
void oskb::on_curlyr_clicked() { this->special_push(OSKB_CRR); }
void oskb::on_ltr_clicked() { this->special_push(OSKB_LTR); }
void oskb::on_ltl_clicked() { this->push(OSKB_LTL); }
void oskb::on_sem_clicked() { this->push(OSKB_SEM);  }
void oskb::on_colon_clicked() { this->special_push(OSKB_COL); }
void oskb::on_comma_clicked() { this->push(OSKB_COM); }
void oskb::on_dot_clicked() { this->push(OSKB_DOT); }
void oskb::on_slash_clicked() { this->push(OSKB_SL); }
void oskb::on_reverse_slash_clicked() { this->push(OSKB_RVSL); }
void oskb::on_vertical_bar_clicked() { this->special_push(OSKB_VB); }
void oskb::on_at_clicked() { this->special_push(OSKB_AT); }
void oskb::on_underscore_clicked() { this->special_push(OSKB_US); }
void oskb::on_dollar_clicked() { this->special_push(OSKB_USD); }
void oskb::on_hashtag_clicked() { this->special_push(OSKB_HT); }
void oskb::on_equals_clicked() { this->push(OSKB_EQ); }

void oskb::on_gech_key_clicked()
{
    this->push(OSKB_F);
    this->push(OSKB_E);
    this->push(OSKB_R);
    this->push(_OSKB_H);
    this->push(OSKB_A);
    this->push(OSKB_T);
    this->push(OSKB_G);
    this->push(OSKB_E);
    this->push(OSKB_C);
    this->push(OSKB_DOT);
    this->push(OSKB_G);
    this->push(OSKB_I);
    this->push(OSKB_T);
    this->push(_OSKB_H);
    this->push(OSKB_U);
    this->push(OSKB_B);
    this->push(OSKB_DOT);
    this->push(OSKB_I);
    this->push(OSKB_O);
    this->push(OSKB_SL);
    this->push(OSKB_L);
    this->push(OSKB_A);
    this->push(OSKB_N);
    this->push(OSKB_D);
    this->push(OSKB_SL);
}

