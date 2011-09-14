case 0x00: {
  op_io();
  opcode_cycle = 0;
  break;
}

case 0xef: {
  op_io(2);
  regs.pc--;
  opcode_cycle = 0;
  break;
}

case 0xff: {
  op_io(2);
  regs.pc--;
  opcode_cycle = 0;
  break;
}

case 0x9f: {
  op_io(4);
  regs.a = (regs.a >> 4) | (regs.a << 4);
  regs.p.n = !!(regs.a & 0x80);
  regs.p.z = (regs.a == 0);
  opcode_cycle = 0;
  break;
}

case 0xdf: {
  op_io(2);
  if(regs.p.c || (regs.a) > 0x99) {
    regs.a += 0x60;
    regs.p.c = 1;
  }
  if(regs.p.h || (regs.a & 15) > 0x09) {
    regs.a += 0x06;
  }
  regs.p.n = !!(regs.a & 0x80);
  regs.p.z = (regs.a == 0);
  opcode_cycle = 0;
  break;
}

case 0xbe: {
  op_io(2);
  if(!regs.p.c || (regs.a) > 0x99) {
    regs.a -= 0x60;
    regs.p.c = 0;
  }
  if(!regs.p.h || (regs.a & 15) > 0x09) {
    regs.a -= 0x06;
  }
  regs.p.n = !!(regs.a & 0x80);
  regs.p.z = (regs.a == 0);
  opcode_cycle = 0;
  break;
}

case 0x60: {
  op_io();
  regs.p.c = 0;
  opcode_cycle = 0;
  break;
}

case 0x20: {
  op_io();
  regs.p.p = 0;
  opcode_cycle = 0;
  break;
}

case 0x80: {
  op_io();
  regs.p.c = 1;
  opcode_cycle = 0;
  break;
}

case 0x40: {
  op_io();
  regs.p.p = 1;
  opcode_cycle = 0;
  break;
}

case 0xe0: {
  op_io();
  regs.p.v = 0;
  regs.p.h = 0;
  opcode_cycle = 0;
  break;
}

case 0xed: {
  op_io(2);
  regs.p.c = !regs.p.c;
  opcode_cycle = 0;
  break;
}

case 0xa0: {
  op_io(2);
  regs.p.i = 1;
  opcode_cycle = 0;
  break;
}

case 0xc0: {
  op_io(2);
  regs.p.i = 0;
  opcode_cycle = 0;
  break;
}

case 0x02: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd |=  0x01;
  op_writedp(dp, rd);
  opcode_cycle = 0;
  break;
}

case 0x12: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd &= ~0x01;
  op_writedp(dp, rd);
  opcode_cycle = 0;
  break;
}

case 0x22: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd |=  0x02;
  op_writedp(dp, rd);
  opcode_cycle = 0;
  break;
}

case 0x32: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd &= ~0x02;
  op_writedp(dp, rd);
  opcode_cycle = 0;
  break;
}

case 0x42: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd |=  0x04;
  op_writedp(dp, rd);
  opcode_cycle = 0;
  break;
}

case 0x52: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd &= ~0x04;
  op_writedp(dp, rd);
  opcode_cycle = 0;
  break;
}

case 0x62: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd |=  0x08;
  op_writedp(dp, rd);
  opcode_cycle = 0;
  break;
}

case 0x72: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd &= ~0x08;
  op_writedp(dp, rd);
  opcode_cycle = 0;
  break;
}

case 0x82: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd |=  0x10;
  op_writedp(dp, rd);
  opcode_cycle = 0;
  break;
}

case 0x92: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd &= ~0x10;
  op_writedp(dp, rd);
  opcode_cycle = 0;
  break;
}

case 0xa2: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd |=  0x20;
  op_writedp(dp, rd);
  opcode_cycle = 0;
  break;
}

case 0xb2: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd &= ~0x20;
  op_writedp(dp, rd);
  opcode_cycle = 0;
  break;
}

case 0xc2: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd |=  0x40;
  op_writedp(dp, rd);
  opcode_cycle = 0;
  break;
}

case 0xd2: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd &= ~0x40;
  op_writedp(dp, rd);
  opcode_cycle = 0;
  break;
}

case 0xe2: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd |=  0x80;
  op_writedp(dp, rd);
  opcode_cycle = 0;
  break;
}

case 0xf2: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd &= ~0x80;
  op_writedp(dp, rd);
  opcode_cycle = 0;
  break;
}

case 0x2d: {
  op_io(2);
  op_writestack(regs.a);
  opcode_cycle = 0;
  break;
}

case 0x4d: {
  op_io(2);
  op_writestack(regs.x);
  opcode_cycle = 0;
  break;
}

case 0x6d: {
  op_io(2);
  op_writestack(regs.y);
  opcode_cycle = 0;
  break;
}

case 0x0d: {
  op_io(2);
  op_writestack(regs.p);
  opcode_cycle = 0;
  break;
}

case 0xae: {
  op_io(2);
  regs.a = op_readstack();
  opcode_cycle = 0;
  break;
}

case 0xce: {
  op_io(2);
  regs.x = op_readstack();
  opcode_cycle = 0;
  break;
}

case 0xee: {
  op_io(2);
  regs.y = op_readstack();
  opcode_cycle = 0;
  break;
}

case 0x8e: {
  op_io(2);
  regs.p = op_readstack();
  opcode_cycle = 0;
  break;
}

case 0xcf: {
  op_io(8);
  ya = regs.y * regs.a;
  regs.a = ya;
  regs.y = ya >> 8;
  //result is set based on y (high-byte) only
  regs.p.n = !!(regs.y & 0x80);
  regs.p.z = (regs.y == 0);
  opcode_cycle = 0;
  break;
}

case 0x9e: {
  op_io(11);
  ya = regs.ya;
  //overflow set if quotient >= 256
  regs.p.v = !!(regs.y >= regs.x);
  regs.p.h = !!((regs.y & 15) >= (regs.x & 15));
  if(regs.y < (regs.x << 1)) {
    //if quotient is <= 511 (will fit into 9-bit result)
    regs.a = ya / regs.x;
    regs.y = ya % regs.x;
  } else {
    //otherwise, the quotient won't fit into regs.p.v + regs.a
    //this emulates the odd behavior of the S-SMP in this case
    regs.a = 255    - (ya - (regs.x << 9)) / (256 - regs.x);
    regs.y = regs.x + (ya - (regs.x << 9)) % (256 - regs.x);
  }
  //result is set based on a (quotient) only
  regs.p.n = !!(regs.a & 0x80);
  regs.p.z = (regs.a == 0);
  opcode_cycle = 0;
  break;
}

