#ifndef __AT89X52_H__
#define __AT89X52_H__

// 字节寄存器
sfr p0      = 0x80;
sfr sp      = 0x81;
sfr dpl     = 0x82;
sfr dph     = 0x83;
sfr pcon    = 0x87;
sfr tcon    = 0x88;
sfr tmod    = 0x89;
sfr tl0     = 0x8A;
sfr tl1     = 0x8B;
sfr th0     = 0x8C;
sfr th1     = 0x8D;
sfr p1      = 0x90;
sfr scon    = 0x98;
sfr sbuf    = 0x99;
sfr p2      = 0xA0;
sfr ie      = 0xA8;
sfr p3      = 0xB0;
sfr ip      = 0xB8;
sfr t2con   = 0xC8;
sfr t2mod   = 0xC9;
sfr rcap2l  = 0xCA;
sfr rcap2h  = 0xCB;
sfr tl2     = 0xCC;
sfr th2     = 0xCD;
sfr psw     = 0xD0;
sfr acc     = 0xE0;
sfr b       = 0xF0;

// P0 的位
sbit p0_0 = 0x80;
sbit p0_1 = 0x81;
sbit p0_2 = 0x82;
sbit p0_3 = 0x83;
sbit p0_4 = 0x84;
sbit p0_5 = 0x85;
sbit p0_6 = 0x86;
sbit p0_7 = 0x87;

// PCON Bit Values
#define IDL_    0x01

#define STOP_   0x02
#define PD_     0x02

#define GF0_    0x04
#define GF1_    0x08
#define SMOD_   0x80

// TCON Bit Registers
sbit it0  = 0x88;
sbit ie0  = 0x89;
sbit it1  = 0x8A;
sbit ie1  = 0x8B;
sbit tr0  = 0x8C;
sbit tf0  = 0x8D;
sbit tr1  = 0x8E;
sbit tf1  = 0x8F;

// TMOD Bit Values
#define T0_M0_   0x01
#define T0_M1_   0x02
#define T0_CT_   0x04
#define T0_GATE_ 0x08
#define T1_M0_   0x10
#define T1_M1_   0x20
#define T1_CT_   0x40
#define T1_GATE_ 0x80

#define T1_MASK_ 0xF0
#define T0_MASK_ 0x0F

// P1 的位
sbit p1_0 = 0x90;
sbit p1_1 = 0x91;
sbit p1_2 = 0x92;
sbit p1_3 = 0x93;
sbit p1_4 = 0x94;
sbit p1_5 = 0x95;
sbit p1_6 = 0x96;
sbit p1_7 = 0x97;

sbit t2   = 0x90; // External input to Timer/Counter 2, clock out
sbit t2ex = 0x91; // Timer/Counter 2 capture/reload trigger & dir ctl

// SCON 的位
sbit ri   = 0x98;
sbit ti   = 0x99;
sbit rb8  = 0x9A;
sbit tb8  = 0x9B;
sbit ren  = 0x9C;
sbit sm2  = 0x9D;
sbit sm1  = 0x9E;
sbit sm0  = 0x9F;

// P2 的位
sbit p2_0 = 0xA0;
sbit p2_1 = 0xA1;
sbit p2_2 = 0xA2;
sbit p2_3 = 0xA3;
sbit p2_4 = 0xA4;
sbit p2_5 = 0xA5;
sbit p2_6 = 0xA6;
sbit p2_7 = 0xA7;

// IE Bit Registers
sbit ex0  = 0xA8; // 1=Enable External interrupt 0
sbit et0  = 0xA9; // 1=Enable Timer 0 interrupt
sbit ex1  = 0xAA; // 1=Enable External interrupt 1
sbit et1  = 0xAB; // 1=Enable Timer 1 interrupt
sbit es   = 0xAC; // 1=Enable Serial port interrupt
sbit et2  = 0xAD; // 1=Enable Timer 2 interrupt

sbit ea   = 0xAF; // 0=Disable all interrupts

// P3 的位
sbit p3_0 = 0xB0;
sbit p3_1 = 0xB1;
sbit p3_2 = 0xB2;
sbit p3_3 = 0xB3;
sbit p3_4 = 0xB4;
sbit p3_5 = 0xB5;
sbit p3_6 = 0xB6;
sbit p3_7 = 0xB7;

sbit rxd  = 0xB0; // Serial data input
sbit txd  = 0xB1; // Serial data output
sbit int0 = 0xB2; // External interrupt 0
sbit int1 = 0xB3; // External interrupt 1
sbit t0   = 0xB4; // Timer 0 external input
sbit t1   = 0xB5; // Timer 1 external input
sbit wr   = 0xB6; // External data memory write strobe
sbit rd   = 0xB7; // External data memory read strobe

// IP 的位
sbit px0  = 0xB8;
sbit pt0  = 0xB9;
sbit px1  = 0xBA;
sbit pt1  = 0xBB;
sbit ps   = 0xBC;
sbit pt2  = 0xBD;

// T2CON 的位
sbit cp_rl2= 0xC8;      // 0=Reload, 1=Capture select
sbit c_t2 = 0xC9;       // 0=Timer, 1=Counter
sbit tr2  = 0xCA;       // 0=Stop timer, 1=Start timer
sbit exen2= 0xCB;       // Timer 2 external enable
sbit tclk = 0xCC;       // 0=Serial clock uses Timer 1 overflow, 1=Timer 2
sbit rclk = 0xCD;       // 0=Serial clock uses Timer 1 overflow, 1=Timer 2
sbit exf2 = 0xCE;       // Timer 2 external flag
sbit tf2  = 0xCF;       // Timer 2 overflow flag

// T2MOD Bit Values
#define DCEN_   0x01    // 1=Timer 2 can be configured as up/down counter
#define T2OE_   0x02    // Timer 2 output enable

// PSW 的位
sbit p    = 0xD0;
sbit f1   = 0xD1;
sbit ov   = 0xD2;
sbit rs0  = 0xD3;
sbit rs1  = 0xD4;
sbit f0   = 0xD5;
sbit ac   = 0xD6;
sbit cy   = 0xD7;

// 中断向量: 地址 = (Number * 8) + 3
#define IE0_VECTOR	0  // 0x03 外部中断 0
#define TF0_VECTOR	1  // 0x0B 计时器 0
#define IE1_VECTOR	2  // 0x13 外部中断 1
#define TF1_VECTOR	3  // 0x1B 计时器 1
#define SIO_VECTOR	4  // 0x23 Serial port

#define TF2_VECTOR	5  // 0x2B 计时器 2
#define EX2_VECTOR	5  // 0x2B 外部中断 2

/// 无符号整数类型的别名
#define uchar unsigned char
#define uint unsigned int

#endif