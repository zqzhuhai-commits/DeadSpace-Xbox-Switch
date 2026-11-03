#include "ds1_funcs.h"
#include "ds1_utf8.h"
extern "C" __attribute__((noinline)) ds1zh::Character ds1_decode(uint8_t* base,uint32_t a) { return ds1zh::Decode(a,[&](uint32_t p){return uint32_t(base[p]);}); }
DEFINE_REX_FUNC(sub_825390C0) {
	REX_FUNC_PROLOGUE();
auto r11 = ctx.r11;
auto r12 = ctx.r12;
auto r20 = ctx.r20;
auto r21 = ctx.r21;
auto r22 = ctx.r22;
auto r23 = ctx.r23;
auto r24 = ctx.r24;
auto r25 = ctx.r25;
auto r26 = ctx.r26;
auto r27 = ctx.r27;
auto r28 = ctx.r28;
auto r29 = ctx.r29;
auto r30 = ctx.r30;
auto r31 = ctx.r31;
auto f0 = ctx.f0;
auto f27 = ctx.f27;
auto f28 = ctx.f28;
auto f29 = ctx.f29;
auto f30 = ctx.f30;
auto f31 = ctx.f31;
auto cr0 = ctx.cr0;
auto cr6 = ctx.cr6;
auto xer = ctx.xer;
 auto ds1_utf8 = [&](uint32_t a) { return ds1_decode(base,a); };
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x8289ed08
	ctx.lr = 0x825390C8;

	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x8289edd4
	ctx.lr = 0x825390D0;

	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// lwz r11,0(r28)
	r11.u64 = REX_LOAD_U32(r28.u32 + 0);
	// mr r20,r8
	r20.u64 = ctx.r8.u64;
	// lfs f28,-11356(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -11356);
	f28.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fmr f29,f28
	f29.f64 = f28.f64;
	// beq cr6,0x82539120
	if (cr6.eq) goto loc_82539120;
	// lwz r11,24(r11)
	r11.u64 = REX_LOAD_U32(r11.u32 + 24);
	// lfs f0,16(r28)
	temp.u32 = REX_LOAD_U32(r28.u32 + 16);
	f0.f64 = double(temp.f32);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f29,f11,f0
	f29.f64 = double(float(ctx.f11.f64 * f0.f64));
loc_82539120:
	// lwz r11,4(r28)
	r11.u64 = REX_LOAD_U32(r28.u32 + 4);
	// fmr f0,f28
	ctx.fpscr.disableFlushMode();
	f0.f64 = f28.f64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82539150
	if (cr6.eq) goto loc_82539150;
	// lwz r11,24(r11)
	r11.u64 = REX_LOAD_U32(r11.u32 + 24);
	// lfs f0,16(r28)
	temp.u32 = REX_LOAD_U32(r28.u32 + 16);
	f0.f64 = double(temp.f32);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f0,f11,f0
	f0.f64 = double(float(ctx.f11.f64 * f0.f64));
loc_82539150:
	// li r23,0
	r23.s64 = 0;
	// fdivs f27,f29,f0
	ctx.fpscr.disableFlushMode();
	f27.f64 = double(float(f29.f64 / f0.f64));
	// fmr f31,f28
	f31.f64 = f28.f64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// mr r26,r23
	r26.u64 = r23.u64;
	// fmr f30,f29
	f30.f64 = f29.f64;
	// beq cr6,0x82539170
	if (cr6.eq) goto loc_82539170;
	// stfs f28,0(r25)
	temp.f32 = float(f28.f64);
	REX_STORE_U32(r25.u32 + 0, temp.u32);
loc_82539170:
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x8253917c
	if (cr6.eq) goto loc_8253917C;
	// stb r23,0(r20)
	REX_STORE_U8(r20.u32 + 0, r23.u8);
loc_8253917C:
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r22,-1
	r22.s64 = -1;
	// li r21,1
	r21.s64 = 1;
loc_82539188:
	// stw r23,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, r23.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r29,r23
	r29.u64 = r23.u64;
	// bl 0x82538d98
	ctx.lr = 0x825391A0;
	sub_82538D98(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U32(r27.u32 + 0);
	// add. r30,r11,r31
	r30.u64 = r11.u64 + r31.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r27)
	REX_STORE_U32(r27.u32 + 0, r11.u32);
	// beq 0x825393bc
	if (cr0.eq) goto loc_825393BC;
	// lbz r11,0(r30)
	r11.u64 = REX_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825393bc
	if (cr6.eq) goto loc_825393BC;
	// lwz r11,4(r28)
	r11.u64 = REX_LOAD_U32(r28.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825392a0
	if (cr6.eq) goto loc_825392A0;
	// stw r22,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, r22.u32);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r6,20(r28)
	ctx.r6.u64 = REX_LOAD_U32(r28.u32 + 20);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82538ef8
	ctx.lr = 0x825391E8;
	sub_82538EF8(ctx, base);
	// lwz r9,0(r27)
	ctx.r9.u64 = REX_LOAD_U32(r27.u32 + 0);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,84(r1)
	r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// add r30,r10,r30
	r30.u64 = ctx.r10.u64 + r30.u64;
	// stw r9,0(r27)
	REX_STORE_U32(r27.u32 + 0, ctx.r9.u32);
	// ble cr6,0x825392a0
	if (!cr6.gt) goto loc_825392A0;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x82539214
	if (cr6.eq) goto loc_82539214;
	// stb r21,0(r20)
	REX_STORE_U8(r20.u32 + 0, r21.u8);
loc_82539214:
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,4(r28)
	ctx.r9.u64 = REX_LOAD_U32(r28.u32 + 4);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lfs f0,24(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r28.u32 + 24);
	f0.f64 = double(temp.f32);
	// addi r8,r10,17
	ctx.r8.s64 = ctx.r10.s64 + 17;
	// fmuls f13,f0,f27
	ctx.f13.f64 = double(float(f0.f64 * f27.f64));
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r7,r9
	r11.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253929c
	if (cr6.eq) goto loc_8253929C;
	// rlwinm r10,r10,2,22,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x3FC;
	// lwzx r11,r10,r11
	r11.u64 = REX_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253929c
	if (cr6.eq) goto loc_8253929C;
	// fmuls f30,f0,f29
	f30.f64 = double(float(f0.f64 * f29.f64));
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8253926c
	if (cr6.eq) goto loc_8253926C;
	// lfs f0,0(r25)
	temp.u32 = REX_LOAD_U32(r25.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f30,f0
	cr6.compare(f30.f64, f0.f64);
	// ble cr6,0x8253926c
	if (!cr6.gt) goto loc_8253926C;
	// stfs f30,0(r25)
	temp.f32 = float(f30.f64);
	REX_STORE_U32(r25.u32 + 0, temp.u32);
loc_8253926C:
	// lhz r11,6(r11)
	r11.u64 = REX_LOAD_U16(r11.u32 + 6);
	// lfs f0,28(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r28.u32 + 28);
	f0.f64 = double(temp.f32);
	// lbz r26,0(r30)
	r26.u64 = REX_LOAD_U8(r30.u32 + 0);
	// mr r29,r21
	r29.u64 = r21.u64;
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmadds f9,f10,f13,f0
	ctx.f9.f64 = double(float(std::fma(ctx.f10.f64, ctx.f13.f64, f0.f64)));
	// fadds f31,f9,f31
	f31.f64 = double(float(ctx.f9.f64 + f31.f64));
	// b 0x825392a0
	goto loc_825392A0;
loc_8253929C:
	// mr r26,r23
	r26.u64 = r23.u64;
loc_825392A0:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8253933c
	if (!cr6.eq) goto loc_8253933C;
	// lbz r31,0(r30)
	r31.u64 = ds1_utf8(r30.u32).value;
	// lwz r3,0(r28)
	ctx.r3.u64 = REX_LOAD_U32(r28.u32 + 0);
	// rlwinm r10,r31,24,8,31
	ctx.r10.u64 = (r31.u32 >> 8) & 0xFF;
	// mr r11,r31
	r11.u64 = r31.u64;
	// addi r9,r10,17
	ctx.r9.s64 = ctx.r10.s64 + 17;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r8,r3
	r11.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82539338
	if (cr6.eq) goto loc_82539338;
	// rlwinm r10,r10,2,22,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x3FC;
	// lwzx r29,r10,r11
	r29.u64 = REX_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82539338
	if (cr6.eq) goto loc_82539338;
	// lfs f0,32(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r28.u32 + 32);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// beq cr6,0x825392f8
	if (cr6.eq) goto loc_825392F8;
	// fadds f31,f0,f31
	f31.f64 = double(float(f0.f64 + f31.f64));
	// b 0x8253933c
	goto loc_8253933C;
loc_825392F8:
	// extsb r11,r31
	r11.u64 = r31.u32 & 0xFFFF;
	// clrlwi r4,r26,24
	ctx.r4.u64 = r26.u32 & 0xFFFF;
	// clrlwi r5,r11,16
	ctx.r5.u64 = r11.u32 & 0xFFFF;
	// bl 0x82571458
	ctx.lr = 0x82539308;
	sub_82571458(ctx, base);
	// lhz r10,6(r29)
	ctx.r10.u64 = REX_LOAD_U16(r29.u32 + 6);
	// lfs f0,28(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r28.u32 + 28);
	f0.f64 = double(temp.f32);
	// mr r26,r31
	r26.u64 = r31.u64;
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r9.u64);
	// lfd f13,104(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fadds f10,f1,f11
	ctx.f10.f64 = double(float(ctx.f1.f64 + ctx.f11.f64));
	// fadds f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 + f0.f64));
	// fadds f31,f9,f31
	f31.f64 = double(float(ctx.f9.f64 + f31.f64));
	// b 0x8253933c
	goto loc_8253933C;
loc_82539338:
	// mr r26,r23
	r26.u64 = r23.u64;
loc_8253933C:
	// lwz r11,0(r27)
	r11.u64 = REX_LOAD_U32(r27.u32 + 0);
	// addi r31,r30,1
	r31.u64 = r30.u32 + ds1_utf8(r30.u32).bytes;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// Byte offset into original UTF-8 string
	r11.u64 = r11.u32 + ds1_utf8(r30.u32).bytes;
	// stw r11,0(r27)
	REX_STORE_U32(r27.u32 + 0, r11.u32);
	// lwz r11,0(r24)
	r11.u64 = REX_LOAD_U32(r24.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,0(r24)
	REX_STORE_U32(r24.u32 + 0, ctx.r10.u32);
	// beq cr6,0x82539370
	if (cr6.eq) goto loc_82539370;
	// lfs f0,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r25.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f30,f0
	cr6.compare(f30.f64, f0.f64);
	// ble cr6,0x82539370
	if (!cr6.gt) goto loc_82539370;
	// stfs f30,0(r25)
	temp.f32 = float(f30.f64);
	REX_STORE_U32(r25.u32 + 0, temp.u32);
loc_82539370:
	// lbz r11,0(r31)
	r11.u64 = REX_LOAD_U8(r31.u32 + 0);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x825393bc
	if (cr6.eq) goto loc_825393BC;
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// beq cr6,0x825393bc
	if (cr6.eq) goto loc_825393BC;
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// beq cr6,0x825393bc
	if (cr6.eq) goto loc_825393BC;
	// cmpwi cr6,r11,92
	cr6.compare<int32_t>(r11.s32, 92, xer);
	// bne cr6,0x825393a4
	if (!cr6.eq) goto loc_825393A4;
	// lbz r10,1(r31)
	ctx.r10.u64 = REX_LOAD_U8(r31.u32 + 1);
	// cmplwi cr6,r10,110
	cr6.compare<uint32_t>(ctx.r10.u32, 110, xer);
	// beq cr6,0x825393bc
	if (cr6.eq) goto loc_825393BC;
loc_825393A4:
	// cmpwi cr6,r11,32
	cr6.compare<int32_t>(r11.s32, 32, xer);
	// beq cr6,0x825393bc
	if (cr6.eq) goto loc_825393BC;
	// cmpwi cr6,r11,91
	cr6.compare<int32_t>(r11.s32, 91, xer);
	// beq cr6,0x825393bc
	if (cr6.eq) goto loc_825393BC;
	// cmpwi cr6,r11,123
	cr6.compare<int32_t>(r11.s32, 123, xer);
	// bne cr6,0x82539188
	if (!cr6.eq) goto loc_82539188;
loc_825393BC:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x8289ee20
	ctx.lr = 0x825393CC;

	// b 0x8289ed58

	return;
}


DEFINE_REX_FUNC(sub_8253B578) {
	REX_FUNC_PROLOGUE();
auto r11 = ctx.r11;
auto r12 = ctx.r12;
auto r14 = ctx.r14;
auto r15 = ctx.r15;
auto r16 = ctx.r16;
auto r17 = ctx.r17;
auto r18 = ctx.r18;
auto r19 = ctx.r19;
auto r20 = ctx.r20;
auto r21 = ctx.r21;
auto r22 = ctx.r22;
auto r23 = ctx.r23;
auto r24 = ctx.r24;
auto r25 = ctx.r25;
auto r26 = ctx.r26;
auto r27 = ctx.r27;
auto r28 = ctx.r28;
auto r29 = ctx.r29;
auto r30 = ctx.r30;
auto r31 = ctx.r31;
auto f0 = ctx.f0;
auto f14 = ctx.f14;
auto f15 = ctx.f15;
auto f16 = ctx.f16;
auto f17 = ctx.f17;
auto f18 = ctx.f18;
auto f19 = ctx.f19;
auto f20 = ctx.f20;
auto f21 = ctx.f21;
auto f22 = ctx.f22;
auto f23 = ctx.f23;
auto f24 = ctx.f24;
auto f25 = ctx.f25;
auto f26 = ctx.f26;
auto f27 = ctx.f27;
auto f28 = ctx.f28;
auto f29 = ctx.f29;
auto f30 = ctx.f30;
auto f31 = ctx.f31;
auto cr0 = ctx.cr0;
auto cr6 = ctx.cr6;
auto xer = ctx.xer;
 auto ds1_utf8 = [&](uint32_t a) { return ds1_decode(base,a); };
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x8289ecf0
	ctx.lr = 0x8253B580;

	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8289eda0
	ctx.lr = 0x8253B588;

	// ld r12,-4096(r1)
	r12.u64 = REX_LOAD_U64(ctx.r1.u32 + -4096);
	// ld r12,-8192(r1)
	r12.u64 = REX_LOAD_U64(ctx.r1.u32 + -8192);
	// ld r12,-12288(r1)
	r12.u64 = REX_LOAD_U64(ctx.r1.u32 + -12288);
	// stwu r1,-15024(r1)
	ea = -15024 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// fmr f15,f1
	ctx.fpscr.disableFlushMode();
	f15.f64 = ctx.f1.f64;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// fmr f23,f3
	f23.f64 = ctx.f3.f64;
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
	// fmr f14,f4
	f14.f64 = ctx.f4.f64;
	// addi r30,r11,-15524
	r30.s64 = r11.s64 + -15524;
	// fmr f18,f5
	f18.f64 = ctx.f5.f64;
	// li r25,0
	r25.s64 = 0;
	// stw r28,15100(r1)
	REX_STORE_U32(ctx.r1.u32 + 15100, r28.u32);
	// lwz r10,32(r26)
	ctx.r10.u64 = REX_LOAD_U32(r26.u32 + 32);
	// mr r14,r4
	r14.u64 = ctx.r4.u64;
	// lwz r11,28(r26)
	r11.u64 = REX_LOAD_U32(r26.u32 + 28);
	// addi r29,r26,28
	r29.s64 = r26.s64 + 28;
	// stw r25,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, r25.u32);
	// lfs f21,-13464(r30)
	temp.u32 = REX_LOAD_U32(r30.u32 + -13464);
	f21.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f24,4168(r30)
	temp.u32 = REX_LOAD_U32(r30.u32 + 4168);
	f24.f64 = double(temp.f32);
	// fsubs f16,f21,f2
	f16.f64 = double(float(f21.f64 - ctx.f2.f64));
	// stw r10,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// fmr f0,f24
	f0.f64 = f24.f64;
	// beq cr6,0x8253b610
	if (cr6.eq) goto loc_8253B610;
	// lwz r11,24(r11)
	r11.u64 = REX_LOAD_U32(r11.u32 + 24);
	// lfs f0,44(r26)
	temp.u32 = REX_LOAD_U32(r26.u32 + 44);
	f0.f64 = double(temp.f32);
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// std r9,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r9.u64);
	// lfd f13,128(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f0,f11,f0
	f0.f64 = double(float(ctx.f11.f64 * f0.f64));
loc_8253B610:
	// fmuls f0,f0,f18
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * f18.f64));
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// beq cr6,0x8253b654
	if (cr6.eq) goto loc_8253B654;
	// lwz r11,24(r10)
	r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// fmr f13,f24
	ctx.f13.f64 = f24.f64;
	// lfs f13,44(r26)
	temp.u32 = REX_LOAD_U32(r26.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// lwz r11,1092(r10)
	r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 1092);
	// std r9,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r9.u64);
	// lfd f12,128(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f13,f10,f13
	ctx.f13.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fmuls f13,f13,f18
	ctx.f13.f64 = double(float(ctx.f13.f64 * f18.f64));
	// beq cr6,0x8253c0c4
	if (cr6.eq) goto loc_8253C0C4;
loc_8253B654:
	// lfs f12,52(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r26.u32 + 52);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32242
	r11.s64 = -2113011712;
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// lwz r10,1092(r14)
	ctx.r10.u64 = REX_LOAD_U32(r14.u32 + 1092);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f17,-16048(r11)
	temp.u32 = REX_LOAD_U32(r11.u32 + -16048);
	f17.f64 = double(temp.f32);
	// fsubs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 - ctx.f11.f64));
	// fdivs f9,f11,f13
	ctx.f9.f64 = double(float(ctx.f11.f64 / ctx.f13.f64));
	// fmuls f8,f10,f17
	ctx.f8.f64 = double(float(ctx.f10.f64 * f17.f64));
	// stfs f8,128(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fmuls f7,f9,f18
	ctx.f7.f64 = double(float(ctx.f9.f64 * f18.f64));
	// stfs f7,160(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// beq cr6,0x8253c0c4
	if (cr6.eq) goto loc_8253C0C4;
	// stfs f24,112(r1)
	temp.f32 = float(f24.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stw r25,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, r25.u32);
	// lfs f0,6972(r30)
	temp.u32 = REX_LOAD_U32(r30.u32 + 6972);
	f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// fmr f25,f0
	f25.f64 = f0.f64;
	// addi r8,r1,104
	ctx.r8.s64 = ctx.r1.s64 + 104;
	// fmr f26,f0
	f26.f64 = f0.f64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// fmr f2,f18
	ctx.f2.f64 = f18.f64;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// fmr f1,f23
	ctx.f1.f64 = f23.f64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stb r25,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, r25.u8);
	// li r24,1
	r24.s64 = 1;
	// mr r23,r25
	r23.u64 = r25.u64;
	// mr r22,r25
	r22.u64 = r25.u64;
	// bl 0x82539488
	ctx.lr = 0x8253B6D0;
	sub_82539488(ctx, base);
	// lwz r10,28(r14)
	ctx.r10.u64 = REX_LOAD_U32(r14.u32 + 28);
	// lis r11,-32051
	r11.s64 = -2100494336;
	// lwz r31,15116(r1)
	r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 15116);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// lfs f0,44(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r26.u32 + 44);
	f0.f64 = double(temp.f32);
	// addi r20,r11,17676
	r20.s64 = r11.s64 + 17676;
	// lfs f19,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	f19.f64 = double(temp.f32);
	// std r9,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r9.u64);
	// lfd f13,120(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// lwz r8,17676(r11)
	ctx.r8.u64 = REX_LOAD_U32(r11.u32 + 17676);
	// lwz r7,4(r20)
	ctx.r7.u64 = REX_LOAD_U32(r20.u32 + 4);
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// lwz r6,8(r20)
	ctx.r6.u64 = REX_LOAD_U32(r20.u32 + 8);
	// lwz r5,12(r20)
	ctx.r5.u64 = REX_LOAD_U32(r20.u32 + 12);
	// stw r8,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r8.u32);
	// stw r7,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r7.u32);
	// stw r6,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r6.u32);
	// stw r5,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r5.u32);
	// fmuls f10,f11,f18
	ctx.f10.f64 = double(float(ctx.f11.f64 * f18.f64));
	// fmuls f22,f10,f0
	f22.f64 = double(float(ctx.f10.f64 * f0.f64));
	// beq cr6,0x8253b7a8
	if (cr6.eq) goto loc_8253B7A8;
	// lwz r3,104(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// stfs f24,108(r1)
	temp.f32 = float(f24.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// fmr f31,f19
	f31.f64 = f19.f64;
	// lbz r11,0(r3)
	r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253b784
	if (cr6.eq) goto loc_8253B784;
loc_8253B748:
	// stw r25,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, r25.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r1,108
	ctx.r9.s64 = ctx.r1.s64 + 108;
	// fmr f2,f18
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f18.f64;
	// addi r8,r1,104
	ctx.r8.s64 = ctx.r1.s64 + 104;
	// fmr f1,f23
	ctx.f1.f64 = f23.f64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r5,r1,116
	ctx.r5.s64 = ctx.r1.s64 + 116;
	// bl 0x82539488
	ctx.lr = 0x8253B76C;
	sub_82539488(ctx, base);
	// lwz r3,104(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lfs f0,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 108);
	f0.f64 = double(temp.f32);
	// fadds f31,f0,f31
	f31.f64 = double(float(f0.f64 + f31.f64));
	// lbz r11,0(r3)
	r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8253b748
	if (!cr6.eq) goto loc_8253B748;
loc_8253B784:
	// cmpwi cr6,r31,1
	cr6.compare<int32_t>(r31.s32, 1, xer);
	// beq cr6,0x8253b7a0
	if (cr6.eq) goto loc_8253B7A0;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x8253b7a8
	if (!cr6.eq) goto loc_8253B7A8;
	// fsubs f0,f14,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f14.f64 - f31.f64));
	// fadds f16,f0,f16
	f16.f64 = double(float(f0.f64 + f16.f64));
	// b 0x8253b7a8
	goto loc_8253B7A8;
loc_8253B7A0:
	// fsubs f0,f14,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f14.f64 - f31.f64));
	// fmadds f16,f0,f17,f16
	f16.f64 = double(float(std::fma(f0.f64, f17.f64, f16.f64)));
loc_8253B7A8:
	// lwz r11,15108(r1)
	r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 15108);
	// fmr f0,f24
	ctx.fpscr.disableFlushMode();
	f0.f64 = f24.f64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8253b7d4
	if (cr6.eq) goto loc_8253B7D4;
	// fsubs f0,f23,f30
	f0.f64 = double(float(f23.f64 - f30.f64));
	// fcmpu cr6,f0,f24
	cr6.compare(f0.f64, f24.f64);
	// bge cr6,0x8253b7c8
	if (!cr6.lt) goto loc_8253B7C8;
	// fmr f0,f24
	f0.f64 = f24.f64;
loc_8253B7C8:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8253b7d4
	if (!cr6.eq) goto loc_8253B7D4;
	// fmuls f0,f0,f17
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * f17.f64));
loc_8253B7D4:
	// lbz r11,15167(r1)
	r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 15167);
	// fadds f28,f0,f15
	ctx.fpscr.disableFlushMode();
	f28.f64 = double(float(f0.f64 + f15.f64));
	// fmr f20,f16
	f20.f64 = f16.f64;
	// fadds f27,f22,f16
	f27.f64 = double(float(f22.f64 + f16.f64));
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// beq cr6,0x8253b820
	if (cr6.eq) goto loc_8253B820;
	// lfs f0,44(r26)
	temp.u32 = REX_LOAD_U32(r26.u32 + 44);
	f0.f64 = double(temp.f32);
	// fdivs f13,f27,f0
	ctx.f13.f64 = double(float(f27.f64 / f0.f64));
	// fmadds f12,f0,f17,f13
	ctx.f12.f64 = double(float(std::fma(f0.f64, f17.f64, ctx.f13.f64)));
	// fctiwz f11,f12
	ctx.f11.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.f11.u64);
	// lwz r11,124(r1)
	r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r10.u64);
	// lfd f10,120(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmuls f27,f8,f0
	f27.f64 = double(float(ctx.f8.f64 * f0.f64));
loc_8253B820:
	// lwz r11,15148(r1)
	r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 15148);
	// addi r10,r1,320
	ctx.r10.s64 = ctx.r1.s64 + 320;
	// li r9,600
	ctx.r9.s64 = 600;
	// sth r25,76(r26)
	REX_STORE_U16(r26.u32 + 76, r25.u16);
	// stw r10,72(r26)
	REX_STORE_U32(r26.u32 + 72, ctx.r10.u32);
	// mr r31,r28
	r31.u64 = r28.u64;
	// sth r9,78(r26)
	REX_STORE_U16(r26.u32 + 78, ctx.r9.u16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r25,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, r25.u32);
	// beq cr6,0x8253b854
	if (cr6.eq) goto loc_8253B854;
	// lwz r11,8(r11)
	r11.u64 = REX_LOAD_U32(r11.u32 + 8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, r11.u32);
loc_8253B854:
	// lbz r11,0(r28)
	r11.u64 = REX_LOAD_U8(r28.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253c090
	if (cr6.eq) goto loc_8253C090;
	// lis r10,-32057
	ctx.r10.s64 = -2100887552;
	// lfs f30,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r30.u32 + 0);
	f30.f64 = double(temp.f32);
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// lwz r27,104(r1)
	r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lis r11,-32047
	r11.s64 = -2100232192;
	// lwz r29,15108(r1)
	r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 15108);
	// lis r9,-32034
	ctx.r9.s64 = -2099380224;
	// addi r10,r10,-14328
	ctx.r10.s64 = ctx.r10.s64 + -14328;
	// addi r8,r8,28732
	ctx.r8.s64 = ctx.r8.s64 + 28732;
	// lis r17,-32036
	r17.s64 = -2099511296;
	// stw r10,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// lis r19,-32036
	r19.s64 = -2099511296;
	// stw r8,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r8.u32);
	// addi r15,r11,-9048
	r15.s64 = r11.s64 + -9048;
	// addi r30,r9,-30288
	r30.s64 = ctx.r9.s64 + -30288;
	// b 0x8253b8a4
	goto loc_8253B8A4;
loc_8253B8A0:
	// lfs f19,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	f19.f64 = double(temp.f32);
loc_8253B8A4:
	// lbz r11,0(r31)
	r11.u64 = REX_LOAD_U8(r31.u32 + 0);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// beq cr6,0x8253bfac
	if (cr6.eq) goto loc_8253BFAC;
	// cmpwi cr6,r11,92
	cr6.compare<int32_t>(r11.s32, 92, xer);
	// bne cr6,0x8253b8c8
	if (!cr6.eq) goto loc_8253B8C8;
	// lbz r10,1(r31)
	ctx.r10.u64 = REX_LOAD_U8(r31.u32 + 1);
	// cmplwi cr6,r10,110
	cr6.compare<uint32_t>(ctx.r10.u32, 110, xer);
	// beq cr6,0x8253bfac
	if (cr6.eq) goto loc_8253BFAC;
loc_8253B8C8:
	// lwz r18,100(r1)
	r18.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// mr r21,r25
	r21.u64 = r25.u64;
	// lbz r16,96(r1)
	r16.u64 = REX_LOAD_U8(ctx.r1.u32 + 96);
loc_8253B8D4:
	// cmplw cr6,r21,r18
	cr6.compare<uint32_t>(r21.u32, r18.u32, xer);
	// blt cr6,0x8253b904
	if (cr6.lt) goto loc_8253B904;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8253bea8
	if (cr6.eq) goto loc_8253BEA8;
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// stw r27,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, r27.u32);
	// bne 0x8253b8fc
	if (!cr0.eq) goto loc_8253B8FC;
	// lwz r31,15100(r1)
	r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 15100);
	// mr r21,r25
	r21.u64 = r25.u64;
	// b 0x8253b904
	goto loc_8253B904;
loc_8253B8FC:
	// lwz r31,176(r1)
	r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 176);
	// addi r21,r18,-1
	r21.s64 = r18.s64 + -1;
loc_8253B904:
	// addi r5,r1,156
	ctx.r5.s64 = ctx.r1.s64 + 156;
	// addi r4,r1,108
	ctx.r4.s64 = ctx.r1.s64 + 108;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82538d98
	ctx.lr = 0x8253B914;
	sub_82538D98(ctx, base);
	// lwz r11,108(r1)
	r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
	// UTF-8 current glyph
	r11.u64 = ds1_utf8(r31.u32).value;
	// mr r28,r11
	r28.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253bea8
	if (cr6.eq) goto loc_8253BEA8;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8253b960
	if (!cr6.eq) goto loc_8253B960;
	// lbz r10,15127(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 15127);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8253b988
	if (!cr6.eq) goto loc_8253B988;
	// lwz r11,156(r1)
	r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// lwz r10,120(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r9,r11,r10
	ctx.r9.u64 = REX_LOAD_U32(r11.u32 + ctx.r10.u32);
	// stw r9,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// bl 0x82538c28
	ctx.lr = 0x8253B95C;
	sub_82538C28(ctx, base);
	// b 0x8253b988
	goto loc_8253B988;
loc_8253B960:
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x8253b988
	if (!cr6.eq) goto loc_8253B988;
	// lwz r11,152(r1)
	r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// lwz r10,140(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// lwz r9,148(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r8,136(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// stw r11,0(r20)
	REX_STORE_U32(r20.u32 + 0, r11.u32);
	// stw r10,4(r20)
	REX_STORE_U32(r20.u32 + 4, ctx.r10.u32);
	// stw r9,8(r20)
	REX_STORE_U32(r20.u32 + 8, ctx.r9.u32);
	// stw r8,12(r20)
	REX_STORE_U32(r20.u32 + 12, ctx.r8.u32);
loc_8253B988:
	// lwz r29,144(r1)
	r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8253b9b4
	if (cr6.eq) goto loc_8253B9B4;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// lwz r6,48(r26)
	ctx.r6.u64 = REX_LOAD_U32(r26.u32 + 48);
	// addi r4,r1,108
	ctx.r4.s64 = ctx.r1.s64 + 108;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82538ef8
	ctx.lr = 0x8253B9B0;
	sub_82538EF8(ctx, base);
	// lwz r11,100(r1)
	r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
loc_8253B9B4:
	// lwz r10,108(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// add r27,r10,r31
	r27.u64 = ctx.r10.u64 + r31.u64;
	// clrlwi r10,r23,24
	ctx.r10.u64 = r23.u32 & 0xFF;
	// ble cr6,0x8253b9e0
	if (!cr6.gt) goto loc_8253B9E0;
	// extsb r28,r11
	r28.s64 = r11.s8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8253b9d8
	if (!cr6.eq) goto loc_8253B9D8;
	// li r24,1
	r24.s64 = 1;
loc_8253B9D8:
	// li r23,1
	r23.s64 = 1;
	// b 0x8253b9f0
	goto loc_8253B9F0;
loc_8253B9E0:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8253b9ec
	if (cr6.eq) goto loc_8253B9EC;
	// li r24,1
	r24.s64 = 1;
loc_8253B9EC:
	// mr r23,r25
	r23.u64 = r25.u64;
loc_8253B9F0:
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// ble cr6,0x8253ba00
	if (!cr6.gt) goto loc_8253BA00;
	// lfs f31,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	f31.f64 = double(temp.f32);
	// b 0x8253ba04
	goto loc_8253BA04;
loc_8253BA00:
	// fmr f31,f18
	ctx.fpscr.disableFlushMode();
	f31.f64 = f18.f64;
loc_8253BA04:
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253bb5c
	if (cr6.eq) goto loc_8253BB5C;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8253c0e0
	ctx.lr = 0x8253BA18;
	sub_8253C0E0(ctx, base);
	// lwz r11,80(r26)
	r11.u64 = REX_LOAD_U32(r26.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8253ba70
	if (!cr6.eq) goto loc_8253BA70;
	// mr r11,r25
	r11.u64 = r25.u64;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// stw r11,-24340(r19)
	REX_STORE_U32(r19.u32 + -24340, r11.u32);
	// stw r10,-24332(r17)
	REX_STORE_U32(r17.u32 + -24332, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,252(r30)
	REX_STORE_U32(r30.u32 + 252, r11.u32);
	// stw r10,256(r30)
	REX_STORE_U32(r30.u32 + 256, ctx.r10.u32);
	// stw r11,264(r30)
	REX_STORE_U32(r30.u32 + 264, r11.u32);
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// stw r10,268(r30)
	REX_STORE_U32(r30.u32 + 268, ctx.r10.u32);
	// stw r9,248(r30)
	REX_STORE_U32(r30.u32 + 248, ctx.r9.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// stw r9,260(r30)
	REX_STORE_U32(r30.u32 + 260, ctx.r9.u32);
	// stw r9,272(r30)
	REX_STORE_U32(r30.u32 + 272, ctx.r9.u32);
	// rlwinm r4,r10,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x825d6698
	ctx.lr = 0x8253BA68;
	sub_825D6698(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825d64c8
	ctx.lr = 0x8253BA70;
	sub_825D64C8(ctx, base);
loc_8253BA70:
	// clrlwi r10,r23,24
	ctx.r10.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8253ba84
	if (cr6.eq) goto loc_8253BA84;
	// lwz r4,1092(r29)
	ctx.r4.u64 = REX_LOAD_U32(r29.u32 + 1092);
	// b 0x8253ba88
	goto loc_8253BA88;
loc_8253BA84:
	// lwz r4,1092(r14)
	ctx.r4.u64 = REX_LOAD_U32(r14.u32 + 1092);
loc_8253BA88:
	// stb r23,36(r26)
	REX_STORE_U8(r26.u32 + 36, r23.u8);
	// cmplwi cr6,r4,4096
	cr6.compare<uint32_t>(ctx.r4.u32, 4096, xer);
	// bge cr6,0x8253baa8
	if (!cr6.lt) goto loc_8253BAA8;
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r15
	r11.u64 = r11.u64 + r15.u64;
	// b 0x8253baac
	goto loc_8253BAAC;
loc_8253BAA8:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8253BAAC:
	// lhz r11,2(r11)
	r11.u64 = REX_LOAD_U16(r11.u32 + 2);
	// cmplwi cr6,r4,4096
	cr6.compare<uint32_t>(ctx.r4.u32, 4096, xer);
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// std r9,224(r1)
	REX_STORE_U64(ctx.r1.u32 + 224, ctx.r9.u64);
	// lfd f0,224(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 224);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fdivs f25,f21,f12
	f25.f64 = double(float(f21.f64 / ctx.f12.f64));
	// bge cr6,0x8253bae4
	if (!cr6.lt) goto loc_8253BAE4;
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r15
	r11.u64 = r11.u64 + r15.u64;
	// b 0x8253bae8
	goto loc_8253BAE8;
loc_8253BAE4:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8253BAE8:
	// lhz r11,4(r11)
	r11.u64 = REX_LOAD_U16(r11.u32 + 4);
	// lwz r9,80(r26)
	ctx.r9.u64 = REX_LOAD_U32(r26.u32 + 80);
	// extsw r8,r11
	ctx.r8.s64 = r11.s32;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// std r8,248(r1)
	REX_STORE_U64(ctx.r1.u32 + 248, ctx.r8.u64);
	// lfd f0,248(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 248);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fdivs f26,f21,f12
	f26.f64 = double(float(f21.f64 / ctx.f12.f64));
	// bne cr6,0x8253bb58
	if (!cr6.eq) goto loc_8253BB58;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8253bb50
	if (cr6.eq) goto loc_8253BB50;
	// lwz r11,-24340(r19)
	r11.u64 = REX_LOAD_U32(r19.u32 + -24340);
	// stw r4,248(r30)
	REX_STORE_U32(r30.u32 + 248, ctx.r4.u32);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// bne cr6,0x8253bb58
	if (!cr6.eq) goto loc_8253BB58;
	// lwz r11,20(r30)
	r11.u64 = REX_LOAD_U32(r30.u32 + 20);
	// lwz r10,356(r30)
	ctx.r10.u64 = REX_LOAD_U32(r30.u32 + 356);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8253bb58
	if (!cr6.eq) goto loc_8253BB58;
	// lwz r11,308(r30)
	r11.u64 = REX_LOAD_U32(r30.u32 + 308);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253bb58
	if (cr6.eq) goto loc_8253BB58;
	// lbz r3,311(r30)
	ctx.r3.u64 = REX_LOAD_U8(r30.u32 + 311);
	// bl 0x825ca140
	ctx.lr = 0x8253BB4C;
	sub_825CA140(ctx, base);
	// b 0x8253bb58
	goto loc_8253BB58;
loc_8253BB50:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825d67d8
	ctx.lr = 0x8253BB58;
	sub_825D67D8(ctx, base);
loc_8253BB58:
	// mr r24,r25
	r24.u64 = r25.u64;
loc_8253BB5C:
	// clrlwi r29,r23,24
	r29.u64 = r23.u32 & 0xFF;
	// fmr f29,f24
	ctx.fpscr.disableFlushMode();
	f29.f64 = f24.f64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8253bba8
	if (cr6.eq) goto loc_8253BBA8;
	// lwz r9,144(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8253be94
	if (cr6.eq) goto loc_8253BE94;
	// li r10,0
	ctx.r10.s64 = 0;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// addi r8,r10,17
	ctx.r8.s64 = ctx.r10.s64 + 17;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r31,r25
	r31.u64 = r25.u64;
	// lwzx r11,r7,r9
	r11.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253bbf8
	if (cr6.eq) goto loc_8253BBF8;
	// rlwinm r10,r10,2,22,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x3FC;
	// lwzx r31,r10,r11
	r31.u64 = REX_LOAD_U32(ctx.r10.u32 + r11.u32);
	// b 0x8253bbf8
	goto loc_8253BBF8;
loc_8253BBA8:
	// Select glyph page from complete UCS-2 value
	r11.u64 = (r28.u32 >> 8) & 0xFF;
	// clrlwi r5,r28,24
	ctx.r5.u64 = r28.u32 & 0xFFFF;
	// addi r11,r11,17
	r11.s64 = r11.s64 + 17;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// lwzx r11,r8,r14
	r11.u64 = REX_LOAD_U32(ctx.r8.u32 + r14.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253bbd4
	if (cr6.eq) goto loc_8253BBD4;
	// rlwinm r10,r9,2,22,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3FC;
	// lwzx r10,r10,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + r11.u32);
loc_8253BBD4:
	// mr r31,r10
	r31.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8253be94
	if (cr6.eq) goto loc_8253BE94;
	// clrlwi r4,r22,24
	ctx.r4.u64 = r22.u32 & 0xFFFF;
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// bl 0x82571458
	ctx.lr = 0x8253BBEC;
	sub_82571458(ctx, base);
	// lfs f0,40(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r26.u32 + 40);
	f0.f64 = double(temp.f32);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fmuls f29,f13,f31
	f29.f64 = double(float(ctx.f13.f64 * f31.f64));
loc_8253BBF8:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8253be94
	if (cr6.eq) goto loc_8253BE94;
	// lhz r10,2(r31)
	ctx.r10.u64 = REX_LOAD_U16(r31.u32 + 2);
	// lfs f0,40(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r26.u32 + 40);
	f0.f64 = double(temp.f32);
	// lhz r8,4(r31)
	ctx.r8.u64 = REX_LOAD_U16(r31.u32 + 4);
	// lfs f13,44(r26)
	temp.u32 = REX_LOAD_U32(r26.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// lhz r11,8(r31)
	r11.u64 = REX_LOAD_U16(r31.u32 + 8);
	// extsw r5,r8
	ctx.r5.s64 = ctx.r8.s32;
	// std r7,272(r1)
	REX_STORE_U64(ctx.r1.u32 + 272, ctx.r7.u64);
	// lfd f8,272(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + 272);
	// std r5,208(r1)
	REX_STORE_U64(ctx.r1.u32 + 208, ctx.r5.u64);
	// lfd f11,208(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 208);
	// extsh r6,r11
	ctx.r6.s64 = r11.s16;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// std r6,296(r1)
	REX_STORE_U64(ctx.r1.u32 + 296, ctx.r6.u64);
	// lfd f12,296(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 296);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f5,f9
	ctx.f5.f64 = double(float(ctx.f9.f64));
	// frsp f4,f7
	ctx.f4.f64 = double(float(ctx.f7.f64));
	// frsp f6,f10
	ctx.f6.f64 = double(float(ctx.f10.f64));
	// fmuls f2,f5,f0
	ctx.f2.f64 = double(float(ctx.f5.f64 * f0.f64));
	// fmuls f1,f4,f0
	ctx.f1.f64 = double(float(ctx.f4.f64 * f0.f64));
	// fmuls f3,f6,f13
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// fmadds f12,f2,f31,f29
	ctx.f12.f64 = double(float(std::fma(ctx.f2.f64, f31.f64, f29.f64)));
	// fmuls f0,f1,f31
	f0.f64 = double(float(ctx.f1.f64 * f31.f64));
	// fmuls f4,f3,f31
	ctx.f4.f64 = double(float(ctx.f3.f64 * f31.f64));
	// fadds f1,f12,f28
	ctx.f1.f64 = double(float(ctx.f12.f64 + f28.f64));
	// bne cr6,0x8253bc88
	if (!cr6.eq) goto loc_8253BC88;
	// clrlwi r11,r16,24
	r11.u64 = r16.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253bc88
	if (cr6.eq) goto loc_8253BC88;
	// lfs f12,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// b 0x8253bc8c
	goto loc_8253BC8C;
loc_8253BC88:
	// fmr f12,f24
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = f24.f64;
loc_8253BC8C:
	// lhz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U16(r31.u32 + 12);
	// fmr f3,f0
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f0.f64;
	// lhz r9,14(r31)
	ctx.r9.u64 = REX_LOAD_U16(r31.u32 + 14);
	// li r11,1
	r11.s64 = 1;
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// lhz r6,18(r31)
	ctx.r6.u64 = REX_LOAD_U16(r31.u32 + 18);
	// extsw r5,r9
	ctx.r5.s64 = ctx.r9.s32;
	// lhz r9,10(r31)
	ctx.r9.u64 = REX_LOAD_U16(r31.u32 + 10);
	// std r7,240(r1)
	REX_STORE_U64(ctx.r1.u32 + 240, ctx.r7.u64);
	// extsw r3,r6
	ctx.r3.s64 = ctx.r6.s32;
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// lhz r8,16(r31)
	ctx.r8.u64 = REX_LOAD_U16(r31.u32 + 16);
	// std r3,288(r1)
	REX_STORE_U64(ctx.r1.u32 + 288, ctx.r3.u64);
	// lfd f8,288(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + 288);
	// std r7,216(r1)
	REX_STORE_U64(ctx.r1.u32 + 216, ctx.r7.u64);
	// lfd f7,216(r1)
	ctx.f7.u64 = REX_LOAD_U64(ctx.r1.u32 + 216);
	// extsw r4,r8
	ctx.r4.s64 = ctx.r8.s32;
	// std r5,304(r1)
	REX_STORE_U64(ctx.r1.u32 + 304, ctx.r5.u64);
	// lfd f10,304(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 304);
	// lwz r10,15148(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 15148);
	// std r4,256(r1)
	REX_STORE_U64(ctx.r1.u32 + 256, ctx.r4.u64);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfd f11,240(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 240);
	// fcfid f2,f11
	ctx.f2.f64 = double(ctx.f11.s64);
	// fcfid f11,f10
	ctx.f11.f64 = double(ctx.f10.s64);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// lfd f9,256(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 256);
	// fcfid f10,f9
	ctx.f10.f64 = double(ctx.f9.s64);
	// fcfid f9,f8
	ctx.f9.f64 = double(ctx.f8.s64);
	// frsp f7,f2
	ctx.f7.f64 = double(float(ctx.f2.f64));
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// frsp f6,f11
	ctx.f6.f64 = double(float(ctx.f11.f64));
	// frsp f2,f9
	ctx.f2.f64 = double(float(ctx.f9.f64));
	// fmuls f11,f7,f25
	ctx.f11.f64 = double(float(ctx.f7.f64 * f25.f64));
	// fmuls f8,f5,f13
	ctx.f8.f64 = double(float(ctx.f5.f64 * ctx.f13.f64));
	// frsp f5,f10
	ctx.f5.f64 = double(float(ctx.f10.f64));
	// fmuls f10,f6,f26
	ctx.f10.f64 = double(float(ctx.f6.f64 * f26.f64));
	// fmadds f13,f8,f31,f27
	ctx.f13.f64 = double(float(std::fma(ctx.f8.f64, f31.f64, f27.f64)));
	// fmuls f9,f5,f25
	ctx.f9.f64 = double(float(ctx.f5.f64 * f25.f64));
	// fmuls f8,f2,f26
	ctx.f8.f64 = double(float(ctx.f2.f64 * f26.f64));
	// fmuls f6,f10,f30
	ctx.f6.f64 = double(float(ctx.f10.f64 * f30.f64));
	// stfs f6,196(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// fsubs f7,f13,f12
	ctx.f7.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fmuls f13,f11,f30
	ctx.f13.f64 = double(float(ctx.f11.f64 * f30.f64));
	// stfs f13,192(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// fmuls f12,f9,f30
	ctx.f12.f64 = double(float(ctx.f9.f64 * f30.f64));
	// stfs f12,200(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// fmuls f5,f8,f30
	ctx.f5.f64 = double(float(ctx.f8.f64 * f30.f64));
	// stfs f5,204(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// fsubs f2,f7,f22
	ctx.f2.f64 = double(float(ctx.f7.f64 - f22.f64));
	// beq cr6,0x8253bde0
	if (cr6.eq) goto loc_8253BDE0;
	// lfs f11,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fadds f10,f1,f0
	ctx.f10.f64 = double(float(ctx.f1.f64 + f0.f64));
	// fmuls f11,f11,f23
	ctx.f11.f64 = double(float(ctx.f11.f64 * f23.f64));
	// lfs f9,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f9,f9,f23
	ctx.f9.f64 = double(float(ctx.f9.f64 * f23.f64));
	// fcmpu cr6,f10,f11
	cr6.compare(ctx.f10.f64, ctx.f11.f64);
	// blt cr6,0x8253bddc
	if (cr6.lt) goto loc_8253BDDC;
	// fadds f9,f9,f11
	ctx.f9.f64 = double(float(ctx.f9.f64 + ctx.f11.f64));
	// fcmpu cr6,f1,f9
	cr6.compare(ctx.f1.f64, ctx.f9.f64);
	// bgt cr6,0x8253bddc
	if (cr6.gt) goto loc_8253BDDC;
	// fcmpu cr6,f1,f11
	cr6.compare(ctx.f1.f64, ctx.f11.f64);
	// bge cr6,0x8253bdb0
	if (!cr6.lt) goto loc_8253BDB0;
	// fsubs f10,f10,f11
	ctx.f10.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// fsubs f9,f12,f13
	ctx.f9.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fdivs f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 / f0.f64));
	// fsubs f7,f21,f8
	ctx.f7.f64 = double(float(f21.f64 - ctx.f8.f64));
	// fmuls f3,f8,f0
	ctx.f3.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fmadds f1,f7,f0,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f7.f64, f0.f64, ctx.f1.f64)));
	// fmadds f6,f9,f7,f13
	ctx.f6.f64 = double(float(std::fma(ctx.f9.f64, ctx.f7.f64, ctx.f13.f64)));
	// stfs f6,192(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// fsubs f1,f1,f11
	ctx.f1.f64 = double(float(ctx.f1.f64 - ctx.f11.f64));
	// b 0x8253bde0
	goto loc_8253BDE0;
loc_8253BDB0:
	// fcmpu cr6,f10,f9
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f10.f64, ctx.f9.f64);
	// ble cr6,0x8253bdd4
	if (!cr6.gt) goto loc_8253BDD4;
	// fsubs f10,f9,f1
	ctx.f10.f64 = double(float(ctx.f9.f64 - ctx.f1.f64));
	// fsubs f9,f12,f13
	ctx.f9.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fdivs f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 / f0.f64));
	// fsubs f7,f21,f8
	ctx.f7.f64 = double(float(f21.f64 - ctx.f8.f64));
	// fmuls f3,f8,f0
	ctx.f3.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fnmsubs f6,f9,f7,f12
	ctx.f6.f64 = double(float(-std::fma(ctx.f9.f64, ctx.f7.f64, -ctx.f12.f64)));
	// stfs f6,200(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
loc_8253BDD4:
	// fsubs f1,f1,f11
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64 - ctx.f11.f64));
	// b 0x8253bde0
	goto loc_8253BDE0;
loc_8253BDDC:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8253BDE0:
	// lwz r10,15156(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 15156);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// ble cr6,0x8253be00
	if (!cr6.gt) goto loc_8253BE00;
	// lwz r9,15100(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 15100);
	// subf r8,r9,r27
	ctx.r8.u64 = r27.u64 - ctx.r9.u64;
	// cmpw cr6,r8,r10
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, xer);
	// ble cr6,0x8253be00
	if (!cr6.gt) goto loc_8253BE00;
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8253BE00:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253be48
	if (cr6.eq) goto loc_8253BE48;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8253be20
	if (cr6.eq) goto loc_8253BE20;
	// lbz r10,15127(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 15127);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8253be48
	if (!cr6.eq) goto loc_8253BE48;
loc_8253BE20:
	// lwz r7,15132(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 15132);
	// cntlzw r10,r29
	ctx.r10.u64 = r29.u32 == 0 ? 32 : __builtin_clz(r29.u32);
	// lwz r11,15140(r1)
	r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 15140);
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lwz r8,15108(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 15108);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r7,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// bl 0x8253c178
	ctx.lr = 0x8253BE48;
	sub_8253C178(ctx, base);
loc_8253BE48:
	// lfs f0,60(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r26.u32 + 60);
	f0.f64 = double(temp.f32);
	// lfs f13,40(r26)
	temp.u32 = REX_LOAD_U32(r26.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f24
	cr6.compare(f0.f64, f24.f64);
	// beq cr6,0x8253be64
	if (cr6.eq) goto loc_8253BE64;
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fmadds f28,f12,f31,f28
	f28.f64 = double(float(std::fma(ctx.f12.f64, f31.f64, f28.f64)));
	// b 0x8253be90
	goto loc_8253BE90;
loc_8253BE64:
	// lhz r11,6(r31)
	r11.u64 = REX_LOAD_U16(r31.u32 + 6);
	// lfs f0,56(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(r26.u32 + 56);
	f0.f64 = double(temp.f32);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,232(r1)
	REX_STORE_U64(ctx.r1.u32 + 232, ctx.r10.u64);
	// lfd f12,232(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 232);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fadds f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 + f0.f64));
	// fmuls f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// fmadds f7,f8,f31,f28
	ctx.f7.f64 = double(float(std::fma(ctx.f8.f64, f31.f64, f28.f64)));
	// fadds f28,f7,f29
	f28.f64 = double(float(ctx.f7.f64 + f29.f64));
loc_8253BE90:
	// mr r22,r28
	r22.u64 = r28.u64;
loc_8253BE94:
	// addi r31,r27,1
	r31.u64 = r27.u32 + ds1_utf8(r27.u32).bytes;
	// lwz r27,104(r1)
	r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r29,15108(r1)
	r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 15108);
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// b 0x8253b8d4
	goto loc_8253B8D4;
loc_8253BEA8:
	// lbz r11,0(r31)
	r11.u64 = REX_LOAD_U8(r31.u32 + 0);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// beq cr6,0x8253bec0
	if (cr6.eq) goto loc_8253BEC0;
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// bne cr6,0x8253bec4
	if (!cr6.eq) goto loc_8253BEC4;
loc_8253BEC0:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
loc_8253BEC4:
	// lbz r11,0(r31)
	r11.u64 = REX_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r11,92
	cr6.compare<uint32_t>(r11.u32, 92, xer);
	// bne cr6,0x8253bee0
	if (!cr6.eq) goto loc_8253BEE0;
	// lbz r11,1(r31)
	r11.u64 = REX_LOAD_U8(r31.u32 + 1);
	// cmplwi cr6,r11,110
	cr6.compare<uint32_t>(r11.u32, 110, xer);
	// bne cr6,0x8253bee0
	if (!cr6.eq) goto loc_8253BEE0;
	// addi r31,r31,2
	r31.s64 = r31.s64 + 2;
loc_8253BEE0:
	// lbz r11,0(r31)
	r11.u64 = REX_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r11,32
	cr6.compare<uint32_t>(r11.u32, 32, xer);
	// bne cr6,0x8253befc
	if (!cr6.eq) goto loc_8253BEFC;
loc_8253BEEC:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// lbz r11,0(r31)
	r11.u64 = REX_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r11,32
	cr6.compare<uint32_t>(r11.u32, 32, xer);
	// beq cr6,0x8253beec
	if (cr6.eq) goto loc_8253BEEC;
loc_8253BEFC:
	// fadds f20,f20,f19
	ctx.fpscr.disableFlushMode();
	f20.f64 = double(float(f20.f64 + f19.f64));
	// lwz r11,116(r1)
	r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// stw r25,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, r25.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fadds f27,f20,f22
	f27.f64 = double(float(f20.f64 + f22.f64));
	// beq cr6,0x8253bf44
	if (cr6.eq) goto loc_8253BF44;
	// lfs f0,44(r26)
	temp.u32 = REX_LOAD_U32(r26.u32 + 44);
	f0.f64 = double(temp.f32);
	// fdivs f13,f27,f0
	ctx.f13.f64 = double(float(f27.f64 / f0.f64));
	// fmadds f12,f0,f17,f13
	ctx.f12.f64 = double(float(std::fma(f0.f64, f17.f64, ctx.f13.f64)));
	// fctiwz f11,f12
	ctx.f11.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,168(r1)
	REX_STORE_U64(ctx.r1.u32 + 168, ctx.f11.u64);
	// lwz r11,172(r1)
	r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 172);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,264(r1)
	REX_STORE_U64(ctx.r1.u32 + 264, ctx.r10.u64);
	// lfd f10,264(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 264);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmuls f27,f8,f0
	f27.f64 = double(float(ctx.f8.f64 * f0.f64));
loc_8253BF44:
	// addi r7,r26,28
	ctx.r7.s64 = r26.s64 + 28;
	// fmr f2,f18
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f18.f64;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// fmr f1,f23
	ctx.f1.f64 = f23.f64;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stb r25,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, r25.u8);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82539488
	ctx.lr = 0x8253BF6C;
	sub_82539488(ctx, base);
	// fmr f0,f24
	ctx.fpscr.disableFlushMode();
	f0.f64 = f24.f64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x8253bf94
	if (cr6.eq) goto loc_8253BF94;
	// fsubs f0,f23,f1
	f0.f64 = double(float(f23.f64 - ctx.f1.f64));
	// fcmpu cr6,f0,f24
	cr6.compare(f0.f64, f24.f64);
	// bge cr6,0x8253bf88
	if (!cr6.lt) goto loc_8253BF88;
	// fmr f0,f24
	f0.f64 = f24.f64;
loc_8253BF88:
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// bne cr6,0x8253bf94
	if (!cr6.eq) goto loc_8253BF94;
	// fmuls f0,f0,f17
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * f17.f64));
loc_8253BF94:
	// fadds f13,f16,f14
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f16.f64 + f14.f64));
	// mr r22,r25
	r22.u64 = r25.u64;
	// fadds f28,f0,f15
	f28.f64 = double(float(f0.f64 + f15.f64));
	// fcmpu cr6,f20,f13
	cr6.compare(f20.f64, ctx.f13.f64);
	// bgt cr6,0x8253c090
	if (cr6.gt) goto loc_8253C090;
	// b 0x8253c084
	goto loc_8253C084;
loc_8253BFAC:
	// cmpwi cr6,r11,92
	cr6.compare<int32_t>(r11.s32, 92, xer);
	// bne cr6,0x8253bfc4
	if (!cr6.eq) goto loc_8253BFC4;
	// lbz r11,1(r31)
	r11.u64 = REX_LOAD_U8(r31.u32 + 1);
	// cmplwi cr6,r11,110
	cr6.compare<uint32_t>(r11.u32, 110, xer);
	// bne cr6,0x8253bfc4
	if (!cr6.eq) goto loc_8253BFC4;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
loc_8253BFC4:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// lbz r11,0(r31)
	r11.u64 = REX_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r11,32
	cr6.compare<uint32_t>(r11.u32, 32, xer);
	// bne cr6,0x8253bfe4
	if (!cr6.eq) goto loc_8253BFE4;
loc_8253BFD4:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// lbz r11,0(r31)
	r11.u64 = REX_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r11,32
	cr6.compare<uint32_t>(r11.u32, 32, xer);
	// beq cr6,0x8253bfd4
	if (cr6.eq) goto loc_8253BFD4;
loc_8253BFE4:
	// fadds f20,f20,f19
	ctx.fpscr.disableFlushMode();
	f20.f64 = double(float(f20.f64 + f19.f64));
	// lwz r11,116(r1)
	r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// stw r25,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, r25.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fadds f27,f20,f22
	f27.f64 = double(float(f20.f64 + f22.f64));
	// beq cr6,0x8253c02c
	if (cr6.eq) goto loc_8253C02C;
	// lfs f0,44(r26)
	temp.u32 = REX_LOAD_U32(r26.u32 + 44);
	f0.f64 = double(temp.f32);
	// fdivs f13,f27,f0
	ctx.f13.f64 = double(float(f27.f64 / f0.f64));
	// fmadds f12,f0,f17,f13
	ctx.f12.f64 = double(float(std::fma(f0.f64, f17.f64, ctx.f13.f64)));
	// fctiwz f11,f12
	ctx.f11.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,168(r1)
	REX_STORE_U64(ctx.r1.u32 + 168, ctx.f11.u64);
	// lwz r11,172(r1)
	r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 172);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,280(r1)
	REX_STORE_U64(ctx.r1.u32 + 280, ctx.r10.u64);
	// lfd f10,280(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 280);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmuls f27,f8,f0
	f27.f64 = double(float(ctx.f8.f64 * f0.f64));
loc_8253C02C:
	// addi r7,r26,28
	ctx.r7.s64 = r26.s64 + 28;
	// fmr f2,f18
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f18.f64;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// fmr f1,f23
	ctx.f1.f64 = f23.f64;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stb r25,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, r25.u8);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82539488
	ctx.lr = 0x8253C054;
	sub_82539488(ctx, base);
	// fmr f0,f24
	ctx.fpscr.disableFlushMode();
	f0.f64 = f24.f64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x8253c07c
	if (cr6.eq) goto loc_8253C07C;
	// fsubs f0,f23,f1
	f0.f64 = double(float(f23.f64 - ctx.f1.f64));
	// fcmpu cr6,f0,f24
	cr6.compare(f0.f64, f24.f64);
	// bge cr6,0x8253c070
	if (!cr6.lt) goto loc_8253C070;
	// fmr f0,f24
	f0.f64 = f24.f64;
loc_8253C070:
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// bne cr6,0x8253c07c
	if (!cr6.eq) goto loc_8253C07C;
	// fmuls f0,f0,f17
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * f17.f64));
loc_8253C07C:
	// fadds f28,f0,f15
	ctx.fpscr.disableFlushMode();
	f28.f64 = double(float(f0.f64 + f15.f64));
	// mr r22,r25
	r22.u64 = r25.u64;
loc_8253C084:
	// lbz r11,0(r31)
	r11.u64 = REX_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8253b8a0
	if (!cr6.eq) goto loc_8253B8A0;
loc_8253C090:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8253c0e0
	ctx.lr = 0x8253C098;
	sub_8253C0E0(ctx, base);
	// lwz r11,152(r1)
	r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// lwz r10,140(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// lwz r9,148(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r8,136(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// stw r25,72(r26)
	REX_STORE_U32(r26.u32 + 72, r25.u32);
	// sth r25,76(r26)
	REX_STORE_U16(r26.u32 + 76, r25.u16);
	// sth r25,78(r26)
	REX_STORE_U16(r26.u32 + 78, r25.u16);
	// stw r11,0(r20)
	REX_STORE_U32(r20.u32 + 0, r11.u32);
	// stw r10,4(r20)
	REX_STORE_U32(r20.u32 + 4, ctx.r10.u32);
	// stw r9,8(r20)
	REX_STORE_U32(r20.u32 + 8, ctx.r9.u32);
	// stw r8,12(r20)
	REX_STORE_U32(r20.u32 + 12, ctx.r8.u32);
loc_8253C0C4:
	// addi r1,r1,15024
	ctx.r1.s64 = ctx.r1.s64 + 15024;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8289edec
	ctx.lr = 0x8253C0D0;

	// b 0x8289ed40

	return;
}

