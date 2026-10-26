	.section .text
	.arm

	.global _dadd

	// USA: func_0200ab28
_dadd:
	stmdb sp!, {r4, lr}
	eors ip, r1, r3
	eormi r3, r3, #0x80000000
	.word 0x4a0002b7
	subs ip, r0, r2
	sbcs lr, r1, r3
	bhs L_002c
	adds r2, r2, ip
	adc r3, r3, lr
	subs r0, r0, ip
	sbc r1, r1, lr
L_002c:
	mov lr, #0x80000000
	mov ip, r1, lsr #0x14
	orr r1, lr, r1, lsl #0xb
	orr r1, r1, r0, lsr #0x15
	mov r0, r0, lsl #0xb
	movs r4, ip, lsl #0x15
	cmnne r4, #0x200000
	beq L_0128
	mov r4, r3, lsr #0x14
	orr r3, lr, r3, lsl #0xb
	orr r3, r3, r2, lsr #0x15
	mov r2, r2, lsl #0xb
	movs lr, r4, lsl #0x15
	beq L_0170
L_0064:
	subs r4, ip, r4
	beq L_00bc
	cmp r4, #0x20
	ble L_00a0
	cmp r4, #0x38
	movge r4, #0x3f
	sub r4, r4, #0x20
	rsb lr, r4, #0x20
	orrs lr, r2, r3, lsl lr
	mov r2, r3, lsr r4
	orrne r2, r2, #1
	adds r0, r0, r2
	adcs r1, r1, #0
	blo L_00e4
	b L_00c8
L_00a0:
	rsb lr, r4, #0x20
	movs lr, r2, lsl lr
	rsb lr, r4, #0x20
	mov r2, r2, lsr r4
	orr r2, r2, r3, lsl lr
	mov r3, r3, lsr r4
	orrne r2, r2, #1
L_00bc:
	adds r0, r0, r2
	adcs r1, r1, r3
	blo L_00e4
L_00c8:
	add ip, ip, #1
	and r4, r0, #1
	movs r1, r1, rrx
	orr r0, r4, r0, rrx
	mov lr, ip, lsl #0x15
	cmn lr, #0x200000
	beq L_02f4
L_00e4:
	movs r2, r0, lsl #0x15
	mov r0, r0, lsr #0xb
	orr r0, r0, r1, lsl #0x15
	add r1, r1, r1
	mov r1, r1, lsr #0xc
	orr r1, r1, ip, lsl #0x14
	tst r2, #0x80000000
	ldmeqia sp!, {r4, lr}
	bxeq lr
	movs r2, r2, lsl #1
	andeqs r2, r0, #1
	ldmeqia sp!, {r4, lr}
	bxeq lr
L_0118:
	adds r0, r0, #1
	adc r1, r1, #0
	ldmia sp!, {r4, lr}
	bx lr
L_0128:
	cmp ip, #0x800
	movge lr, #0x80000000
	movlt lr, #0
	bics ip, ip, #0x800
	beq L_0194
	orrs r4, r0, r1, lsl #1
	bne L_02d0
	mov r4, r3, lsr #0x14
	mov r3, r3, lsl #0xb
	orr r3, r3, r2, lsr #0x15
	mov r2, r2, lsl #0xb
	movs r4, r4, lsl #0x15
	beq L_02bc
	cmn r4, #0x200000
	bne L_02bc
	orrs r4, r2, r3, lsl #1
	beq L_02bc
	b L_02d0
L_0170:
	cmp r4, #0x800
	movge lr, #0x80000000
	movlt lr, #0
	bic ip, ip, #0x800
	bics r4, r4, #0x800
	beq L_0200
	orrs r4, r2, r3, lsl #1
	bne L_02d0
	b L_02bc
L_0194:
	orrs r4, r0, r1, lsl #1
	beq L_01d4
	mov ip, #1
	bic r1, r1, #0x80000000
	mov r4, r3, lsr #0x14
	mov r3, r3, lsl #0xb
	orr r3, r3, r2, lsr #0x15
	mov r2, r2, lsl #0xb
	movs r4, r4, lsl #0x15
	cmnne r4, #0x200000
	mov r4, r4, lsr #0x15
	orr r4, r4, lr, lsr #0x14
	beq L_0170
	orr r3, r3, #0x80000000
	orr ip, ip, lr, lsr #0x14
	b L_0064
L_01d4:
	mov ip, r3, lsr #0x14
	mov r1, r3, lsl #0xb
	orr r1, r1, r2, lsr #0x15
	mov r0, r2, lsl #0xb
	movs r4, ip, lsl #0x15
	beq L_0288
	cmn r4, #0x200000
	bne L_0288
	orrs r4, r0, r1, lsl #1
	beq L_02bc
	b L_02d4
L_0200:
	orrs r4, r2, r3, lsl #1
	beq L_0298
	mov r4, #1
	bic r3, r3, #0x80000000
	cmp r1, #0
	bpl L_0224
	orr ip, ip, lr, lsr #0x14
	orr r4, r4, lr, lsr #0x14
	b L_0064
L_0224:
	adds r0, r0, r2
	adcs r1, r1, r3
	blo L_0244
	add ip, ip, #1
	and r4, r0, #1
	movs r1, r1, rrx
	mov r0, r0, rrx
	orr r0, r0, r4
L_0244:
	cmp r1, #0
	subges ip, ip, #1
	movs r2, r0, lsl #0x15
	mov r0, r0, lsr #0xb
	orr r0, r0, r1, lsl #0x15
	add r1, r1, r1
	orr r1, lr, r1, lsr #0xc
	orr r1, r1, ip, lsl #0x14
	ldmeqia sp!, {r4, lr}
	bxeq lr
	tst r2, #0x80000000
	ldmeqia sp!, {r4, lr}
	bxeq lr
	movs r2, r2, lsl #1
	andeqs r2, r0, #1
	ldmeqia sp!, {r4, lr}
	bxeq lr
L_0288:
	mov r1, r3
	mov r0, r2
	ldmia sp!, {r4, lr}
	bx lr
L_0298:
	cmp r1, #0
	subges ip, ip, #1
	mov r0, r0, lsr #0xb
	orr r0, r0, r1, lsl #0x15
	add r1, r1, r1
	orr r1, lr, r1, lsr #0xc
	orr r1, r1, ip, lsl #0x14
	ldmia sp!, {r4, lr}
	bx lr
L_02bc:
	ldr r1, [pc, #0x50]
	orr r1, lr, r1
	mov r0, #0
	ldmia sp!, {r4, lr}
	bx lr
L_02d0:
	mov r1, r3
L_02d4:
	mvn r0, #0
	bic r1, r0, #0x80000000
	ldmia sp!, {r4, lr}
	bx lr
L_02e4:
	mvn r0, #0
	bic r1, r0, #0x80000000
	ldmia sp!, {r4, lr}
	bx lr
L_02f4:
	cmp ip, #0x800
	movge lr, #0x80000000
	movlt lr, #0
	ldr r1, [pc, #0xc]
	orr r1, lr, r1
	mov r0, #0
	ldmia sp!, {r4, lr}
	bx lr

	.balign 4
L_0314:
	.word 0x7ff00000
