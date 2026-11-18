typedef unsigned long long uint64_t;
typedef unsigned char uint8_t;
int mouseY = 0;
int mouseX = 0;
int cursor = 0;
void print(const char* text){
    char* vga = (char*)0xB8000;

    for(int i = 0;text[i] != 0x00;i++){
        if (cursor >= 80 * 25)
        return;
        vga[cursor * 2] = text[i];
        vga[cursor * 2 + 1] = 0x0F;
        cursor++;
} 
}
extern "C" void kernel_main(){
    print("Welcome to the MIOS 1.5.2 BETA operating system.\n");
}
unsigned char inb(unsigned short portt){
unsigned char result;
asm volatile("inb %1, %0" : "=a"(result) : "Nd"(portt));
return result;
} extern "C" void keyboart(unsigned char a){
    switch (a){
    case 0x04:
    print("a");
    break;
    case 0x05:
    print("b");
    break;
    case 0x06:
    print("c");
    break;
    case 0x07:
    print("d");
    break;
    case 0x08:
    print("e");
    break;
    case 0x09:
    print("f");
    break;
    case 0x0A:
    print("g");
    break;
    case 0x0B:
    print("h");
    break;
    case 0x0C:
    print("i");
    break;
    case 0x0D:
    print("j");
    break;
    case 0x0E:
    print("k");
    break;
    case 0x0F:
    print("l");
    break;
    case 0x10:
    print("m");
    break;
    case 0x11:
    print("n");
    break;
    case 0x12:
    print("o");
    break;
    case 0x13:
    print("p");
    break;
    case 0x14:
    print("q");
    break;
    case 0x15:
    print("r");
    break;
    case 0x16:
    print("s");
    break;
    case 0x17:
    print("t");
    break;
    case 0x18:
    print("u");
    break; 
    case 0x19:
    print("v");
    break;
    case 0x1A:
    print("w");
    break;
    case 0x1B:
    print("x");
    break;
    case 0x1C:
    print("y");
    break;
    case 0x1D:
    print("z");
    break;
    case 0x28:
    print("\n");
    break;
    case 0x2B:
    print("    ");
    break;
    case 0x2C:
    print(" ");
    break;
    case 0x1E:
    print("1");
    break;
}
}

void usb_keyboard(uint8_t* oldreport){
    for(int i = 2;i < 8;i++){
        if (oldreport[i] == 0x04){ 
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x05){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x06){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x07){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x08){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x09){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x0A){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x0B){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x0C){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x0D){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x0E){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x0F){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x10){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x11){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x12){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x13){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x14){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x15){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x16){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x17){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x18){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x19){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x1A){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x1B){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x1C){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x1D){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x28){
            keyboart(oldreport[i]);
        } else if (oldreport[i] ==0x2B){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x2C){
            keyboart(oldreport[i]);
        } else if (oldreport[i] == 0x1E){
            keyboart(oldreport[i]);
        }
    }
}
void mouse_vga(int x, int y){
    char* vga = (char*)0xB8000;
    int position = (y * 80 + x) * 2;
    vga[position] = '>';
    vga[position + 1] = 0x0F;
}
extern "C" void mouse_usb(uint8_t* reports, int x = 0, int y = 0){
    mouseX += x;
    mouseY -= y;

if (mouseX < 0) mouseX = 0;
if (mouseY < 0) mouseY = 0;
if (mouseX > 79) mouseX = 79;
if (mouseY > 24) mouseY = 24;
        if (reports[0] == 0x01) {
            print("Left button pressed\n");
        }else if (reports[0] == 0x02) {
            print("Right button pressed\n");
        } else if (reports[0] == 0x04) {
            print("Middle button pressed\n");
        } else if (reports[0] == 0x03){
            print("Left and right pressed\n");
        }
    mouse_vga(mouseX, mouseY);
} 

extern "C" void command(unsigned char h, unsigned char e, unsigned char l, unsigned char p, uint8_t enterrrrrr){
    if (h == 0x0B && e == 0x08 && l == 0x0F && p == 0x13){
        if (enterrrrrr == 0x28){
    print("command: clear, help, color,cal,version,creater, - color it's yellow color, cal it's Display Logo and display version\n");
}
} 
} extern "C" void command_clear(unsigned char cc, unsigned char ll, unsigned char e, unsigned char a, unsigned char r){
    if (cc == 0x06 && ll == 0x0F && e == 0x08 && a == 0x04 && r == 0x15){
    char* vgaa = (char*)0xB8000;
    for(int i = 0;i < 80 * 25;i++){
        vgaa[i * 2] = ' ';
        vgaa[i * 2 + 1] = 0x0F;
    }
    cursor = 0;
}
} extern "C" void command_color(unsigned char c, unsigned char o , unsigned char l, unsigned char o2, unsigned char r){
    if (c == 0x06 && o == 0x12 && l == 0x0F && o2 == 0x12 && r == 0x15){
    char* vgaaa = (char*)0xB8000;
    for(int i = 0;i < 80 * 25;i++){
        vgaaa[i * 2 + 1] = 0x02;
    }
}
} extern "C" void mouse_driver(uint8_t* driver){
    if (driver[0] == 0x00){
        return;
    } else if (driver[0] == 0x01){
        mouse_usb(driver);
    } else if (driver[0] == 0x02){
        mouse_usb(driver);
    } else if (driver[0] == 0x03){
        mouse_usb(driver);
    } else if (driver[0] == 0x04){
        mouse_usb(driver);
    }
} extern "C" void command_version(uint8_t en, unsigned char v, unsigned e, unsigned r, unsigned s, unsigned i, unsigned o, unsigned n){
    if (v == 0x19 && e == 0x08 && r == 0x15 && s == 0x16 && i == 0x0C && o == 0x12 && n == 0x11){
        if (en == 0x28){
            print("version MIOS: 1.5.2 BETA\n");
        }
    }
} extern "C" void command_cal(uint8_t ennnnnnnnnnnnnnnnnn, unsigned char c, unsigned char a, unsigned char l){
    if (c == 0x06 && a == 0x04 && l == 0x0F){
        if (ennnnnnnnnnnnnnnnnn == 0x28){
            print("╔═══ MIOS ═══╗ Hello MIOS version: 1.5.2 BETA\n");
        }
    }
} extern "C" void creater(uint8_t ennnnnnnnnnnnnnnnnnnnnnnn, unsigned char c, unsigned char r, unsigned char e, unsigned char a, unsigned char t, unsigned char ee, unsigned char rr){
    if (c == 0x06 && r == 0x15 && e == 0x08 && a == 0x04 && t == 0x17 && ee == 0x08 && rr == 0x15){
        if (ennnnnnnnnnnnnnnnnnnnnnnn == 0x28){
            print("creater name: Sasha, data: 13.11.2026\n");
        }
    }
}extern "C" void error(uint8_t epqq, unsigned char e, unsigned char r, unsigned char rr, unsigned char o, unsigned char rrr){
    if (e == 0x08 && r == 0x15 && rr == 0x15 && o == 0x12 && rrr == 0x15){
        if (epqq == 0x28){
            print("ERROR 0x02, 0x04, 0x00, 0x08, 0x10, 0x0C, 0x17, and all bytes, result: error panic\n");
        }
    }
} extern "C" void information(uint8_t wthrgwetwh, unsigned char i, unsigned char n, unsigned char f, unsigned char o){
    if (i == 0x0C && n == 0x11 && f == 0x09 && o == 0x12){
        if (wthrgwetwh == 0x28){
            print("info: version 1.5.2 BETA creater name: SASHA data: 13.11.2026 system: USB on version MIOS 2.5.2 BETA will be ps/2\n");
        }
    }
}