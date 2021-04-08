#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char g_buf[1024];

//3 递归和非全局变量
int inverse4(char* str, char* dst)
{
    if (str == NULL) {
        return -1;
    }

    if (*str == '\0') {// 递归技术的条件
        return 0;
    }

    if (inverse4(str + 1, dst) < 0) {
        return -1;
    }

    strncat(dst, str, 1);

    return 0;
}

//2 递归和全局变量(把逆序的结果放在全局变量里)
int inverse3(char* str)
{
    if (str == NULL) {
        return -1;
    }

    if (*str == '\0') {// 递归技术的条件
        return 0;
    }

    if (inverse3(str + 1) < 0) {
        return -1;
    }

    strncat(g_buf, str, 1);

    return 0;
}

//1 通过递归的方式逆序打印
int inverse2(char* str)
{
    if (str == NULL) {
        return -1;
    }

    if (*str == '\0') {// 递归技术的条件
        return 0;
    }

    if (inverse2(str + 1) < 0) {
        return -1;
    }
    printf("%c", *str);
    return 0;
}

int main(void)
{
    char buf[] = "abcdefg";
    char dst_buf[128] = { 0 };

    // test inverse()
    //printf("buf : %s\n", inverse(buf));

    // test inverse2();
    //inverse2(buf);

    // test inverse3();
    //inverse3(buf);
    //printf("g_buf : %s\n", g_buf);

    // test inverse4();
    inverse4(buf, dst_buf);
    printf("dst_buf : %s\n", dst_buf);


    return 0;
}