#include <stdio.h>
#include <memory.h>
#define gc() getchar_unlocked()
int mem[100001];
char input[4096];
char data[4096];
int LOOPINFO[4096][2];
int stack[4096];

int fRI() {
	register int N = gc(), r = 0;
	for (; 0x30>N || N>0x3A; N = gc());
	do {
		r = (r << 3) + (r << 1) + (N & 0b1111); N = gc();
	} while (0x30 <= N);
	return r;
}
int main(int argc, char** argv) {
	register int T = fRI(), sm, sc, si, pointer, idx, inputidx, j, jump;
	while (T--) {
		sm = fRI(); sc = fRI(); si = fRI();
		memset(mem, 0, sizeof(int)*sm);
		memset(LOOPINFO, 0, sizeof(LOOPINFO));
		pointer = idx = inputidx = jump = 0;
		for (j = 0; j <= sc; ++j) {
			input[j] = gc();
			if (input[j] == '[') {
				stack[pointer++] = j;
			}
			else if (input[j] == ']') {
				LOOPINFO[j][0] = stack[--pointer];
				LOOPINFO[stack[pointer]][0] = j;
			}
		}
		for (j = 0; j <= si; ++j)
			data[j] = gc();
		pointer = 0;
		for (j = 0; j <= 50000000&&idx<sc; j++) {
			switch (input[idx]) {
			case '-': mem[pointer] = mem[pointer] ? mem[pointer] - 1 : 255;	jump = 0;break;
			case '+': mem[pointer] = !((mem[pointer] + 1) ^ 256) ? 0 : mem[pointer] + 1; jump = 0;			break;
			case '<': pointer = pointer ? pointer - 1 : sm - 1;	jump = 0;			break;
			case '>': pointer = !((pointer + 1) ^ sm) ? 0 : pointer + 1; jump = 0;	break;
			case '[':
				if (!mem[pointer])	idx = LOOPINFO[idx][0] - 1, jump = 1;
				else LOOPINFO[idx][1] = 1, jump = 0;
				break;
			case ']':
				if (mem[pointer])
					idx = LOOPINFO[idx][0] - 1,	jump = 1;
				else{
					if (!jump)	LOOPINFO[idx][1] = 1;
					jump = 0;
				}
				break;
			case ',': mem[pointer] = inputidx == si ? 255 : data[inputidx++]; jump = 0; break;
			default: jump = 0;  break;
			}
			++idx;
		}
		if (!(idx^sc)) printf("Terminates\n");
		else
			for (j = 1; j < sc; ++j)
				if (input[j] == ']'&&LOOPINFO[LOOPINFO[j][0]][1] && !LOOPINFO[j][1]) {printf("Loops %d %d\n", LOOPINFO[j][0], j);break;	}
	}
}
