#include <jni.h>
#include "org_midnightas_jgetch_JGetch.h"

#ifdef __linux__
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#elif _WIN32
#include <conio.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __linux__
int getch() {
	struct termios oldattr, newattr;
	int ch;
	tcgetattr( STDIN_FILENO, &oldattr );
	newattr = oldattr;
	newattr.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	return ch;
}
#endif

JNIEXPORT jint JNICALL Java_org_midnightas_jgetch_JGetch_getch(JNIEnv *env, jclass clazz) {
	return (jint) getch();
}

#ifdef __cplusplus
}
#endif
