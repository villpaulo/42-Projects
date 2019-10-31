.name		"Lolita"
.comment	"Carlos t'a massacre"

entry:
	aff		r1
	sti		r1, %:beegees_gen, %1
	sti		r1, %:beegees, %1
	sti		r1, %:cc_spawn, %1
	sti		r1, %:wall, %1
	sti		r1, %:wall2, %1
	sti		r1, %:cc_spawn, %9
	sti		r1, %:cc_spawn, %17
	sti		r1, %:wall, %95
	ld		%0, r16
	fork	%:cc_spawn

wall_prep:
	ld		%0, r2
	ld		%0, r16

wall:
	live	%4902343
	st		r2, -24
	st		r2, -33
	st		r2, -42
	st		r2, -51
	st		r2, -60
	st		r2, -69
	st		r2, -78
	st		r2, -87
	st		r2, -96
	st		r2, -105
	st		r2, -114
	st		r2, -123
	st		r2, -132
	st		r2, -141
	st		r2, -150
	st		r2, -159
	st		r2, -168
	st		r2, -177
	st		r2, -186
	st		r2, -195
	st		r2, -204
	st		r2, -213
	live	%12345
	st		r2, -222
	st		r2, -231
	st		r2, -240
	st		r2, -249
	st		r2, -258
	st		r2, -267
	st		r2, -276
	st		r2, -285
	st		r2, -294
	st		r2, -303
	st		r2, -312
	st		r2, -321
	st		r2, -330
	st		r2, -339
	st		r2, -348
	st		r2, -357
	st		r2, -366
	st		r2, -375
	st		r2, -384
	st		r2, -393
	st		r2, -402
	st		r2, -411
	st		r2, -420
	st		r2, -429
	st		r2, -438
	st		r2, -447
	st		r2, -456
	st		r2, -465
	st		r2, -474
	st		r2, -483
	st		r2, -492
	st		r2, -501
	zjmp	%:wall
beegees_gen:
	live	%4239423
	fork	%:beegees_gen
	ld		%0, r16

beegees:
	live	%3442302
	zjmp	%:beegees

cc_spawn:
	live	%4320423
	fork	%:wall_prep
	live	%12345
	fork	%:beegees_gen
	live	%12345
	zjmp	%3
	fork	%:cc_spawn

wall_prep2:
	ld		%0, r2

wall2:
	live	%4902343
	st		r2, 267
	st		r2, 266
	st		r2, 265
	st		r2, 264
	st		r2, 263
	st		r2, 262
	st		r2, 261
	st		r2, 260
	st		r2, 259
	st		r2, 258
	st		r2, 257
	st		r2, 256
	st		r2, 255
	st		r2, 254
	st		r2, 253
	st		r2, 252
	st		r2, 251
	st		r2, 250
	st		r2, 259
	st		r2, 258
	st		r2, 257
	st		r2, 256
	st		r2, 255
	st		r2, 254
	st		r2, 253
	st		r2, 252
	st		r2, 251
	st		r2, 250
	st		r2, 249
	st		r2, 248
	st		r2, 247
	st		r2, 246
	st		r2, 245
	st		r2, 244
	st		r2, 243
	st		r2, 242
	st		r2, 241
	st		r2, 240
	st		r2, 239
	st		r2, 238
	st		r2, 237
	st		r2, 236
	st		r2, 235
	st		r2, 234
	st		r2, 233
	st		r2, 232
	st		r2, 231
	st		r2, 230
	st		r2, 229
	st		r2, 228
	zjmp	%:wall
