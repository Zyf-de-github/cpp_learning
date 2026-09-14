#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX 100
//
//typedef struct {
//    int start;
//    int size;
//    int state; // 0:空闲, 1:已分配
//} Partition;
//
//Partition parts[MAX];
//int part_count = 0;
//
//void init_memory(int total_size) {
//    parts[0].start = 0;
//    parts[0].size = total_size;
//    parts[0].state = 0;
//    part_count = 1;
//}
//
//void show_memory() {
//    printf("\n内存状态：\n");
//    printf("起始地址\t大小\t状态\n");
//    for (int i = 0; i < part_count; i++) {
//        printf("%d\t\t%d\t%s\n", parts[i].start, parts[i].size,
//            parts[i].state == 0 ? "空闲" : "已分配");
//    }
//}
//
//void merge_free() {
//    for (int i = 0; i < part_count - 1; i++) {
//        if (parts[i].state == 0 && parts[i + 1].state == 0) {
//            parts[i].size += parts[i + 1].size;
//            for (int j = i + 1; j < part_count - 1; j++)
//                parts[j] = parts[j + 1];
//            part_count--;
//            i--;
//        }
//    }
//}
//
//int first_fit(int size) {
//    for (int i = 0; i < part_count; i++) {
//        if (parts[i].state == 0 && parts[i].size >= size) {
//            if (parts[i].size > size) {
//                for (int j = part_count; j > i + 1; j--)
//                    parts[j] = parts[j - 1];
//                parts[i + 1].start = parts[i].start + size;
//                parts[i + 1].size = parts[i].size - size;
//                parts[i + 1].state = 0;
//                part_count++;
//                parts[i].size = size;
//            }
//            parts[i].state = 1;
//            return i;
//        }
//    }
//    return -1;
//}
//
//int best_fit(int size) {
//    int best = -1;
//    int min_size = 999999;
//    for (int i = 0; i < part_count; i++) {
//        if (parts[i].state == 0 && parts[i].size >= size && parts[i].size < min_size) {
//            min_size = parts[i].size;
//            best = i;
//        }
//    }
//    if (best != -1) {
//        if (parts[best].size > size) {
//            for (int j = part_count; j > best + 1; j--)
//                parts[j] = parts[j - 1];
//            parts[best + 1].start = parts[best].start + size;
//            parts[best + 1].size = parts[best].size - size;
//            parts[best + 1].state = 0;
//            part_count++;
//            parts[best].size = size;
//        }
//        parts[best].state = 1;
//    }
//    return best;
//}
//
//void free_memory(int start) {
//    for (int i = 0; i < part_count; i++) {
//        if (parts[i].start == start && parts[i].state == 1) {
//            parts[i].state = 0;
//            merge_free();
//            return;
//        }
//    }
//    printf("未找到起始地址为 %d 的已分配块\n", start);
//}
//
//int main() {
//    init_memory(1024);
//    int choice, size, start;
//
//    while (1) {
//        printf("\n1. 首次适应分配\n2. 最佳适应分配\n3. 释放内存\n4. 显示内存\n5. 退出\n选择: ");
//        scanf("%d", &choice);
//        switch (choice) {
//        case 1:
//            printf("输入分配大小: ");
//            scanf("%d", &size);
//            if (first_fit(size) != -1)
//                printf("分配成功\n");
//            else
//                printf("分配失败\n");
//            break;
//        case 2:
//            printf("输入分配大小: ");
//            scanf("%d", &size);
//            if (best_fit(size) != -1)
//                printf("分配成功\n");
//            else
//                printf("分配失败\n");
//            break;
//        case 3:
//            printf("输入释放的起始地址: ");
//            scanf("%d", &start);
//            free_memory(start);
//            break;
//        case 4:
//            show_memory();
//            break;
//        case 5:
//            exit(0);
//        default:
//            printf("无效选择\n");
//        }
//    }
//    return 0;
//}


#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 10
#define MAX_PAGES 30

// FIFO
void fifo(int pages[], int n, int frames) {
    int memory[MAX_FRAMES], front = 0, faults = 0;
    for (int i = 0; i < frames; i++) memory[i] = -1;

    printf("\nFIFO 置换过程：\n");
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < frames; j++)
            if (memory[j] == pages[i]) found = true;

        if (!found) {
            memory[front] = pages[i];
            front = (front + 1) % frames;
            faults++;
        }

        for (int j = 0; j < frames; j++)
            printf("%d ", memory[j]);
        printf("\n");
    }
    printf("缺页次数: %d\n", faults-3);
}

// LRU
void lru(int pages[], int n, int frames) {
    int memory[MAX_FRAMES], used[MAX_FRAMES], faults = 0;

    for (int i = 0; i < frames; i++) memory[i] = -1, used[i] = 0;

    printf("\nLRU 置换过程：\n");
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < frames; j++) {
            if (memory[j] == pages[i]) {
                found = true;
                used[j] = i;
                break;
            }
        }

        if (!found) {
            int lru = 0;
            for (int j = 1; j < frames; j++)
                if (used[j] < used[lru]) lru = j;
            memory[lru] = pages[i];
            used[lru] = i;
            faults++;
        }

        for (int j = 0; j < frames; j++)
            printf("%d ", memory[j]);
        printf("\n");
    }
    printf("缺页次数: %d\n", faults-3);
}

// OPT
void opt(int pages[], int n, int frames) {
    int memory[MAX_FRAMES], faults = 0;

    for (int i = 0; i < frames; i++) memory[i] = -1;

    printf("\nOPT 置换过程：\n");
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < frames; j++)
            if (memory[j] == pages[i]) found = true;

        if (!found) {
            int replace = -1, farthest = i;
            for (int j = 0; j < frames; j++) {
                int k;
                for (k = i + 1; k < n; k++)
                    if (memory[j] == pages[k]) break;
                if (k == n) {
                    replace = j;
                    break;
                }
                if (k > farthest) {
                    farthest = k;
                    replace = j;
                }
            }
            if (replace == -1) replace = 0;
            memory[replace] = pages[i];
            faults++;
        }

        for (int j = 0; j < frames; j++)
            printf("%d ", memory[j]);
        printf("\n");
    }
    printf("缺页次数: %d\n", faults-3);
}

int main() {
    int pages[] = { 2,3,2,1,5,2,4,5,3,2,5,2 };
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames;

    printf("输入页框数: ");
    scanf("%d", &frames);

    fifo(pages, n, frames);
    lru(pages, n, frames);
    opt(pages, n, frames);

    return 0;
}