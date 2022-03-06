//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//struct SUBWAY
//{
//    char list[100];
//    struct SUBWAY* way[6];
//    int change;
//    int changeCount;
//    int transNum;
//};
//
//struct WAY
//{
//    char way[100];
//}subway[100];
//
//struct TRANS
//{
//    struct SUBWAY* transWay[6];
//    int transLine[6];
//    char list[100];
//}transSearchList[100];
//
//int trans_i = 0;
//
//bool Read_file(const char fname[], struct SUBWAY* head, struct SUBWAY* first);
//void Plus_subway(char fname[]);
//void Search_list(char firstList[], char secondList[]);
//int Transfer(char firstList[], char secondList[], int c3, int transCount, int deter);
//void First_Search_way(char firstList[]);
//int First_Search_Trans(char firstList[], int firstSearchCount, int fsDeter);
//
//struct SUBWAY* ptr = NULL;
//struct SUBWAY* prev;
//char subwayList[100][100][100];
//int global_c[200] = { 0, }, global_cCount = 0;
//bool trans;
//int subwayChange, globalSubwayCount = 0;
//char transList[50], firstSearchList[100], firstTransList[100];
//
////20220209 2호선에서 환승할 때 다음역이 list에 저장되지 않고 넘어가진다. 그 다음 것이 저장됨
//int main()
//{
//    char firstList[100];
//    char secondList[100];
//    struct SUBWAY* head;
//    head = (struct SUBWAY*)malloc(sizeof(struct SUBWAY));
//    struct SUBWAY* plusTemp = NULL;
//    if (head == NULL)
//    {
//        printf("malloc failed\n");
//        return false;
//    }
//    struct SUBWAY* first;
//    first = (struct SUBWAY*)malloc(sizeof(struct SUBWAY));
//    char fname[20] = "subway.txt";
//    if (!Read_file(fname, head, first))
//    {
//        printf("failed");
//        return -1;
//    }
//    ptr = head->way[0];
//    strcpy(fname, "one2.txt");
//    Plus_subway(fname);
//    strcpy(fname, "five2.txt");
//    Plus_subway(fname);
//    strcpy(fname, "five1.txt");
//    Plus_subway(fname);
//    strcpy(fname, "nine2.txt");
//    Plus_subway(fname);
//    strcpy(fname, "six2.txt");
//    Plus_subway(fname);
//    strcpy(fname, "eleven2.txt");
//    Plus_subway(fname);
//    strcpy(fname, "three2.txt");
//    Plus_subway(fname);
//    strcpy(fname, "four2.txt");
//    Plus_subway(fname);
//    strcpy(fname, "ten2.txt");
//    Plus_subway(fname);
//    strcpy(fname, "seven2.txt");
//    Plus_subway(fname);
//    strcpy(fname, "airport.txt");
//    Plus_subway(fname);
//    printf("\n\n");
//    ptr = head->way[0];
//    printf("START: ");
//    gets_s(firstList, sizeof(firstList));
//    printf("END: ");
//    gets_s(secondList, sizeof(secondList));
//    First_Search_way(firstList);
//    if (strcmp(ptr->list, firstList) == 0)
//        printf("First Search Success\n\n");
//    else
//        printf("First Search Failed: %s\n\n", ptr->list);
//    Search_list(firstList, secondList);
//    printf("\n\n");
//}
//
////Construct subwaylist
//bool Read_file(const char fname[], struct SUBWAY* head, struct SUBWAY* first)
//{
//    int i = 0;
//    int first_ct = 0;
//    FILE* pfile;
//    pfile = fopen(fname, "r");
//    while (fscanf(pfile, "%s", subway[i].way) == 1)
//    {
//        struct SUBWAY* node;
//        node = (struct SUBWAY*)malloc(sizeof(struct SUBWAY));
//        for (int wayInit = 0; wayInit < 6; wayInit++)
//            node->way[wayInit] = NULL;
//        if (node == NULL)
//        {
//            printf("malloc failed\n");
//            return false;
//        }
//        if (first_ct == 0)
//        {
//            head->way[0] = node;
//            first = node;
//            ptr = node;
//            prev = NULL;
//            first_ct++;
//            int k;
//            if (subway[i].way[2] == '*')
//            {
//                node->change = 3;
//                for (k = 3; subway[i].way[k] != '\0'; k++)
//                {
//                    node->list[k - 3] = subway[i].way[k];
//                }
//                node->list[k - 3] = '\0';
//            }
//            else if (subway[i].way[1] == '*')
//            {
//                node->change = 2;
//                for (k = 2; subway[i].way[k] != '\0'; k++)
//                {
//                    node->list[k - 2] = subway[i].way[k];
//                }
//                node->list[k - 2] = '\0';
//            }
//            else if (subway[i].way[0] == '*')
//            {
//                node->change = 1;
//                for (k = 1; subway[i].way[k] != '\0'; k++)
//                {
//                    node->list[k - 1] = subway[i].way[k];
//                }
//                node->list[k - 1] = '\0';
//            }
//            else
//            {
//                strcpy(node->list, subway[i].way);
//                node->change = 0;
//            }
//            node->changeCount = 100;
//        }
//        else
//        {
//            int k;
//            if (subway[i].way[2] == '*')
//            {
//                node->change = 3;
//                for (k = 3; subway[i].way[k] != '\0'; k++)
//                {
//                    node->list[k - 3] = subway[i].way[k];
//                }
//                node->list[k - 3] = '\0';
//            }
//            else if (subway[i].way[1] == '*')
//            {
//                node->change = 2;
//                for (k = 2; subway[i].way[k] != '\0'; k++)
//                {
//                    node->list[k - 2] = subway[i].way[k];
//                }
//                node->list[k - 2] = '\0';
//            }
//            else if (subway[i].way[0] == '*')
//            {
//                node->change = 1;
//                for (k = 1; subway[i].way[k] != '\0'; k++)
//                {
//                    node->list[k - 1] = subway[i].way[k];
//                }
//                node->list[k - 1] = '\0';
//            }
//            else
//            {
//                strcpy(node->list, subway[i].way);
//                node->change = 0;
//            }
//            node->changeCount = 100;
//            node->transNum = 2;
//        }
//        if (node->change != 0)
//        {
//            bool input = false;
//            for (int i2 = 0; i2 < 100; i2++)
//            {
//                if (strcmp(transSearchList[i2].list, node->list) == 0)
//                {
//                    for (int j = 0; j < 6; j++)
//                    {
//                        if (!(transSearchList[i2].transLine[j]))
//                        {
//                            transSearchList[i2].transLine[j] = 2;
//                            transSearchList[i2].transWay[j] = node;
//                            input = true;
//                            break;
//                        }
//                    }
//                    break;
//                }
//            }
//            if (!input)
//            {
//                strcpy(transSearchList[trans_i].list, node->list);
//                transSearchList[trans_i].transWay[0] = node;
//                transSearchList[trans_i].transLine[0] = 2;
//                trans_i++;
//            }
//        }
//        if (strcmp(node->list, "Daerim") == 0)
//        {
//            first->way[1] = node; //20220124 node, &node의 차이
//            node->way[0] = first;
//            node->way[1] = ptr;
//            ptr->way[0] = node;
//        }
//        else
//        {
//            ptr->way[0] = node;
//            node->way[1] = ptr;
//        }
//        ptr = node;
//        i++;
//    }
//    fclose(pfile);
//    return true;
//}
//
////Add another subwaylist
//void Plus_subway(char fname[])
//{
//    int transNumber;
//    struct SUBWAY* temp;
//    temp = (struct SUBWAY*)malloc(sizeof(struct SUBWAY));
//    if (temp == NULL)
//    {
//        printf("malloc failed\n");
//        return;
//    }
//    struct SUBWAY* nodeTemp;
//    nodeTemp = (struct SUBWAY*)malloc(sizeof(struct SUBWAY));
//    if (nodeTemp == NULL)
//    {
//        printf("malloc failed\n");
//        return;
//    }
//    char word[100][50];
//    temp = ptr;
//    int i = 0;
//    FILE* pfile;
//    pfile = fopen(fname, "r");
//    if (strcmp(fname, "one2.txt") == 0)
//        transNumber = 1;
//    else if (strcmp(fname, "five2.txt") == 0 || strcmp(fname, "five1.txt") == 0)
//        transNumber = 5;
//    else if (strcmp(fname, "three2.txt") == 0)
//        transNumber = 3;
//    else if (strcmp(fname, "four2.txt") == 0)
//        transNumber = 4;
//    else if (strcmp(fname, "seven2.txt") == 0)
//        transNumber = 7;
//    else if (strcmp(fname, "eleven2.txt") == 0)
//        transNumber = 11;
//    else if (strcmp(fname, "ten2.txt") == 0)
//        transNumber = 10;
//    else if (strcmp(fname, "nine2.txt") == 0)
//        transNumber = 9;
//    else if (strcmp(fname, "six2.txt") == 0)
//        transNumber = 6;
//    else if (strcmp(fname, "airport.txt") == 0)
//        transNumber = 12;
//    while (fscanf(pfile, "%s", &word[i]) == 1)
//    {
//        struct SUBWAY* node;
//        node = (struct SUBWAY*)malloc(sizeof(struct SUBWAY));
//        for (int wayInit = 0; wayInit < 6; wayInit++)
//            node->way[wayInit] = NULL;
//        if (node == NULL)
//        {
//            printf("malloc failed\n");
//            return;
//        }
//        if (i == 0)
//        {
//            ptr = node;
//            node->changeCount = 100;
//            node->change = 0;
//        }
//        else
//        {
//            ptr->way[0] = node;
//            node->way[1] = ptr;
//            node->change = 0;
//            node->changeCount = 100;
//        }
//        int k;
//        if (word[i][2] == '*')
//        {
//            node->change = 3;
//            for (k = 3; word[i][k] != '\0'; k++)
//            {
//                node->list[k - 3] = word[i][k];
//            }
//            node->list[k - 3] = '\0';
//        }
//        else if (word[i][1] == '*')
//        {
//            node->change = 2;
//            for (k = 2; word[i][k] != '\0'; k++)
//            {
//                node->list[k - 2] = word[i][k];
//            }
//            node->list[k - 2] = '\0';
//        }
//        else if (word[i][0] == '*')
//        {
//            node->change = 1;
//            for (k = 1; word[i][k] != '\0'; k++)
//            {
//                node->list[k - 1] = word[i][k];
//            }
//            node->list[k - 1] = '\0';
//        }
//        else
//        {
//            strcpy(node->list, word[i]);
//        }
//        node->transNum = transNumber;
//        //store transfer address 2022-02-28
//        if (node->change != 0)
//        {
//            bool input = false;
//            for (int i2 = 0; i2 < 100; i2++)
//            {
//                if (strcmp(transSearchList[i2].list, node->list) == 0)
//                {
//                    for (int j = 0; j < 6; j++)
//                    {
//                        if (!(transSearchList[i2].transLine[j]))
//                        {
//                            transSearchList[i2].transLine[j] = transNumber;
//                            transSearchList[i2].transWay[j] = node;
//                            input = true;
//                            break;
//                        }
//                    }
//                    break;
//                }
//            }
//            if (!input)
//            {
//                strcpy(transSearchList[trans_i].list, node->list);
//                transSearchList[trans_i].transWay[0] = node;
//                transSearchList[trans_i].transLine[0] = transNumber;
//                trans_i++;
//            }
//        }
//        ptr = node;
//        nodeTemp = node;
//        i++;
//    }
//    ptr = temp;
//    fclose(pfile);
//    return;
//}
//
////Search subway
//void Search_list(char firstList[], char secondList[])
//{
//    //Transfer를 합쳐버릴까?
//    //Transfer시, way를 어떤 기준으로 계속 판단할 것인가?
//    int c1 = 0, c2 = 0, deter = 0;
//    struct SUBWAY* tfTemp1;
//    struct SUBWAY* tfTemp0;
//    struct SUBWAY* tfTemp2;
//    struct SUBWAY* firstTemp = NULL;
//    int fIndex, sIndex, tfC1, tfC2, transCount = 0, change1, change2;
//    firstTemp = ptr;
//    subwayChange = 0;
//    while (ptr)
//    {
//        if (global_cCount > 50)
//            break;
//        strcpy(subwayList[global_cCount][c1], ptr->list);
//        ptr->changeCount = deter;
//        if (strcmp(ptr->list, secondList) == 0 || c1 >= 50)
//            break;
//        if (ptr->change != 0 && transCount < 7)
//        {
//            tfTemp0 = ptr;
//            for (int i = 0; i < 100; i++)
//            {
//                if (strcmp(transSearchList[i].list, ptr->list) == 0)
//                {
//                    for (int j = 0; j < 6; j++)
//                    {
//                        if (transSearchList[i].transLine[j] != ptr->transNum && transSearchList[i].transLine[j] != 0)
//                        {
//                            ptr = transSearchList[i].transWay[j];
//                            tfTemp1 = ptr;
//                            for (int tf1 = 0; tf1 < 2; tf1++)
//                            {
//                                if (ptr->way[0] && ptr->way[0]->changeCount != deter && ptr->way[0]->changeCount != deter - 1 && ptr->way[0]->changeCount != deter - 2 && ptr->way[0]->changeCount != deter - 3 && ptr->way[0]->changeCount != deter - 4 && ptr->way[0]->changeCount != deter - 5 && ptr->way[0]->changeCount != deter - 6)
//                                    ptr = ptr->way[0];
//                                else if (ptr->way[1] && ptr->way[1]->changeCount != deter && ptr->way[1]->changeCount != deter - 1 && ptr->way[1]->changeCount != deter - 2 && ptr->way[1]->changeCount != deter - 3 && ptr->way[1]->changeCount != deter - 4 && ptr->way[1]->changeCount != deter - 5 && ptr->way[1]->changeCount != deter - 6)
//                                    ptr = ptr->way[1];
//                                else
//                                    break;
//                                int tfDeter = deter + 1;
//                                int transfer = Transfer(firstList, secondList, c1, transCount, tfDeter);
//                                transCount++;
//                                if (transfer == 0)
//                                {
//                                    for (int q = c1 + 1; q <= 50; q++)
//                                    {
//                                        for (int p = 0; p <= 100; p++)
//                                            subwayList[global_cCount][q][p] = '\0';
//                                    }
//                                    ptr = tfTemp1;
//                                }
//                                else
//                                {
//                                    global_c[global_cCount] = transfer;
//                                    global_cCount++;
//                                    ptr = tfTemp1;
//                                    for (int q = 0; q <= c1; q++)
//                                        strcpy(subwayList[global_cCount][q], subwayList[global_cCount - 1][q]);
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//            ptr = tfTemp0;
//        }
//        if (ptr->way[0] && ptr->way[0]->changeCount != deter && ptr->way[0]->changeCount != deter - 1 && ptr->way[0]->changeCount != deter - 2 && ptr->way[0]->changeCount != deter - 3 && ptr->way[0]->changeCount != deter - 4 && ptr->way[0]->changeCount != deter - 5 && ptr->way[0]->changeCount != deter - 6)
//            ptr = ptr->way[0];
//        else
//        {
//            c1 = 100;
//            break;
//        }
//        c1++;
//    }
//    fIndex = global_cCount;
//    global_cCount++;
//    ptr = firstTemp;
//    transCount = 0;
//    deter = -100;
//    while (ptr)
//    {
//        if (global_cCount > 50)
//            break;
//        strcpy(subwayList[global_cCount][c2], ptr->list);
//        ptr->changeCount = deter;
//        if (strcmp(ptr->list, secondList) == 0 || c2 >= 50)
//            break;
//        if (ptr->change != 0 && transCount < 7)
//        {
//            tfTemp0 = ptr;
//            for (int i = 0; i < 100; i++)
//            {
//                if (strcmp(transSearchList[i].list, ptr->list) == 0)
//                {
//                    for (int j = 0; j < 6; j++)
//                    {
//                        if (transSearchList[i].transLine[j] != ptr->transNum && transSearchList[i].transLine[j] != 0)
//                        {
//                            ptr = transSearchList[i].transWay[j];
//                            tfTemp2 = ptr;
//                            for (int tf1 = 0; tf1 < 2; tf1++)
//                            {
//                                if (ptr->way[0] && ptr->way[0]->changeCount != deter && ptr->way[0]->changeCount != deter - 1 && ptr->way[0]->changeCount != deter - 2 && ptr->way[0]->changeCount != deter - 3 && ptr->way[0]->changeCount != deter - 4 && ptr->way[0]->changeCount != deter - 5 && ptr->way[0]->changeCount != deter - 6)
//                                    ptr = ptr->way[0];
//                                else if (ptr->way[1] && ptr->way[1]->changeCount != deter && ptr->way[1]->changeCount != deter - 1 && ptr->way[1]->changeCount != deter - 2 && ptr->way[1]->changeCount != deter - 3 && ptr->way[1]->changeCount != deter - 4 && ptr->way[1]->changeCount != deter - 5 && ptr->way[1]->changeCount != deter - 6)
//                                    ptr = ptr->way[1];
//                                else
//                                    break;
//                                int tfDeter = deter + 1;
//                                transCount++;
//                                int transfer = Transfer(firstList, secondList, c2, transCount, tfDeter);
//                                if (transfer == 0)
//                                {
//                                    for (int q = c2 + 1; q <= 50; q++)
//                                    {
//                                        for (int p = 0; p <= 100; p++)
//                                            subwayList[global_cCount][q][p] = '\0';
//                                    }
//                                    ptr = tfTemp2;
//                                }
//                                else
//                                {
//                                    global_c[global_cCount] = transfer;
//                                    global_cCount++;
//                                    ptr = tfTemp2;
//                                    for (int q = 0; q <= c1; q++)
//                                        strcpy(subwayList[global_cCount][q], subwayList[global_cCount - 1][q]);
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//            ptr = tfTemp0;
//        }
//        if (ptr->way[1] && ptr->way[1]->changeCount != deter && ptr->way[1]->changeCount != deter - 1 && ptr->way[1]->changeCount != deter - 2 && ptr->way[1]->changeCount != deter - 3 && ptr->way[1]->changeCount != deter - 4 && ptr->way[1]->changeCount != deter - 5 && ptr->way[1]->changeCount != deter - 6)
//            ptr = ptr->way[1];
//        else
//        {
//            c2 = 100;
//            break;
//        }
//        c2++;
//    }
//    sIndex = global_cCount;
//    printf("\n\nBEST WAY\n");
//    //Compare
//    int min;
//    int minIndex;
//    min = c1;
//    if (c1 < c2)
//        min = c1;
//    else
//        min = c2;
//    for (int cp = 0; cp < global_cCount; cp++)
//    {
//        if (min > global_c[cp] && global_c[cp] != 0)
//        {
//            min = global_c[cp];
//            minIndex = cp;
//        }
//    }
//    if (min == c1)
//    {
//        for (int f = 0; f <= c1; f++)
//        {
//            if (f == c1)
//                printf("%s", subwayList[fIndex][f]);
//            else
//                printf("%s->", subwayList[fIndex][f]);
//        }
//    }
//    else if (min == c2)
//    {
//        for (int f = 0; f <= c2; f++)
//        {
//            if (f == c2)
//                printf("%s", subwayList[sIndex][f]);
//            else
//                printf("%s->", subwayList[sIndex][f]);
//        }
//    }
//    else
//    {
//        for (int f = 0; f <= global_c[minIndex]; f++)
//        {
//            if (f == global_c[minIndex])
//                printf("%s", subwayList[minIndex][f]);
//            else
//                printf("%s->", subwayList[minIndex][f]);
//        }
//    }
//    return;
//}
//
//int Transfer(char firstList[], char secondList[], int c3, int transCount, int deter)
//{
//    struct SUBWAY* tfTemp3;
//    struct SUBWAY* tfTemp0_3;
//    c3++;
//    while (ptr)
//    {
//        strcpy(subwayList[global_cCount][c3], ptr->list);
//        ptr->changeCount = deter;
//        if (strcmp(ptr->list, secondList) == 0)
//            return c3;
//        else if (c3 >= 50)
//            return 0;
//        else if (strcmp(ptr->list, firstList) == 0)
//            return 0;
//        if (ptr->change != 0 && transCount < 7)
//        {
//            tfTemp0_3 = ptr;
//            for (int i = 0; i < 100; i++)
//            {
//                if (strcmp(transSearchList[i].list, ptr->list) == 0)
//                {
//                    for (int j = 0; j < 6; j++)
//                    {
//                        if (transSearchList[i].transLine[j] != ptr->transNum && transSearchList[i].transLine[j] != 0)
//                        {
//                            ptr = transSearchList[i].transWay[j];
//                            tfTemp3 = ptr;
//                            for (int tf3 = 0; tf3 < 2; tf3++)
//                            {
//                                if (ptr->way[0] && ptr->way[0]->changeCount != deter && ptr->way[0]->changeCount != deter - 1 && ptr->way[0]->changeCount != deter - 2 && ptr->way[0]->changeCount != deter - 3 && ptr->way[0]->changeCount != deter - 4 && ptr->way[0]->changeCount != deter - 5 && ptr->way[0]->changeCount != deter - 6)
//                                    ptr = ptr->way[0];
//                                else if (ptr->way[1] && ptr->way[1]->changeCount != deter && ptr->way[1]->changeCount != deter - 1 && ptr->way[1]->changeCount != deter - 2 && ptr->way[1]->changeCount != deter - 3 && ptr->way[1]->changeCount != deter - 4 && ptr->way[1]->changeCount != deter - 5 && ptr->way[1]->changeCount != deter - 6)
//                                    ptr = ptr->way[1];
//                                else
//                                    break;
//                                int tfDeter = deter + 1;
//                                transCount++;
//                                int transfer = Transfer(firstList, secondList, c3, transCount, tfDeter);
//                                if (transfer == 0)
//                                {
//                                    for (int q = c3 + 1; q <= 50; q++)
//                                    {
//                                        for (int p = 0; p <= 100; p++)
//                                            subwayList[global_cCount][q][p] = '\0';
//                                    }
//                                    ptr = tfTemp3;
//                                }
//                                else
//                                {
//                                    global_c[global_cCount] = transfer;
//                                    global_cCount++;
//                                    ptr = tfTemp3;
//                                    for (int q = 0; q <= c3; q++)
//                                        strcpy(subwayList[global_cCount][q], subwayList[global_cCount - 1][q]);
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//            ptr = tfTemp0_3;
//        }
//        if (ptr->way[0] && ptr->way[0]->changeCount != deter && ptr->way[0]->changeCount != deter - 1 && ptr->way[0]->changeCount != deter - 2 && ptr->way[0]->changeCount != deter - 3 && ptr->way[0]->changeCount != deter - 4 && ptr->way[0]->changeCount != deter - 5 && ptr->way[0]->changeCount != deter - 6)
//            ptr = ptr->way[0];
//        else if (ptr->way[1] && ptr->way[1]->changeCount != deter && ptr->way[1]->changeCount != deter - 1 && ptr->way[1]->changeCount != deter - 2 && ptr->way[1]->changeCount != deter - 3 && ptr->way[1]->changeCount != deter - 4 && ptr->way[1]->changeCount != deter - 5 && ptr->way[1]->changeCount != deter - 6)
//            ptr = ptr->way[1];
//        else
//            return 0;
//        c3++;
//    }
//}
//
//void First_Search_way(char firstList[])
//{
//    struct SUBWAY* tfTempFs;
//    struct SUBWAY* tfTempFs1;
//    struct SUBWAY* tfTemp;
//    int fsDeter = 1000, firstSearchCount = 0;
//    tfTemp = ptr;
//    while (ptr)
//    {
//        ptr->changeCount = fsDeter;
//        if (strcmp(ptr->list, firstList) == 0)
//            return;
//        if (ptr->change != 0 && firstSearchCount < 7)
//        {
//            tfTempFs = ptr;
//            for (int i = 0; i < 100; i++)
//            {
//                if (strcmp(transSearchList[i].list, ptr->list) == 0)
//                {
//                    for (int j = 0; j < 6; j++)
//                    {
//                        if (transSearchList[i].transLine[j] != ptr->transNum && transSearchList[i].transLine[j] != 0)
//                        {
//                            ptr = transSearchList[i].transWay[j];
//                            //ptr->changeCount = fsDeter + 1;
//                            tfTempFs1 = ptr;
//                            for (int tf1 = 0; tf1 < 2; tf1++)
//                            {
//                                if (ptr->way[0] && ptr->way[0]->changeCount != fsDeter && ptr->way[0]->changeCount != fsDeter - 1 && ptr->way[0]->changeCount != fsDeter - 2 && ptr->way[0]->changeCount != fsDeter - 3 && ptr->way[0]->changeCount != fsDeter - 4 && ptr->way[0]->changeCount != fsDeter - 5 && ptr->way[0]->changeCount != fsDeter - 6)
//                                    ptr = ptr->way[0];
//                                else if (ptr->way[1] && ptr->way[1]->changeCount != fsDeter && ptr->way[1]->changeCount != fsDeter - 1 && ptr->way[1]->changeCount != fsDeter - 2 && ptr->way[1]->changeCount != fsDeter - 3 && ptr->way[1]->changeCount != fsDeter - 4 && ptr->way[1]->changeCount != fsDeter - 5 && ptr->way[1]->changeCount != fsDeter - 6)
//                                    ptr = ptr->way[1];
//                                else
//                                    break;
//                                int tfFirstDeter = fsDeter + 1;
//                                firstSearchCount++;
//                                int firstTransfer = First_Search_Trans(firstList, firstSearchCount, tfFirstDeter);
//                                if (firstTransfer == 0)
//                                {
//                                    ptr = tfTempFs1;
//                                }
//                                else if (firstTransfer == 1)
//                                {
//                                    return;
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//            ptr = tfTempFs;
//        }
//        if (ptr->way[0] && ptr->way[0]->changeCount != fsDeter && ptr->way[0]->changeCount != fsDeter - 1 && ptr->way[0]->changeCount != fsDeter - 2 && ptr->way[0]->changeCount != fsDeter - 3 && ptr->way[0]->changeCount != fsDeter - 4 && ptr->way[0]->changeCount != fsDeter - 5 && ptr->way[0]->changeCount != fsDeter - 6)
//            ptr = ptr->way[0];
//        else
//            break;
//    }
//    ptr = tfTemp;
//    firstSearchCount = 0;
//    fsDeter = 2000;
//    while (ptr)
//    {
//        ptr->changeCount = fsDeter;
//        if (strcmp(ptr->list, firstList) == 0)
//            return;
//        if (ptr->change != 0 && firstSearchCount < 7)
//        {
//            tfTempFs = ptr;
//            for (int i = 0; i < 100; i++)
//            {
//                if (strcmp(transSearchList[i].list, ptr->list) == 0)
//                {
//                    for (int j = 0; j < 6; j++)
//                    {
//                        if (transSearchList[i].transLine[j] != ptr->transNum && transSearchList[i].transLine[j] != 0)
//                        {
//                            ptr = transSearchList[i].transWay[j];
//                            //ptr->changeCount = fsDeter + 1;
//                            tfTempFs1 = ptr;
//                            for (int tf1 = 0; tf1 < 2; tf1++)
//                            {
//                                if (ptr->way[0] && ptr->way[0]->changeCount != fsDeter && ptr->way[0]->changeCount != fsDeter - 1 && ptr->way[0]->changeCount != fsDeter - 2 && ptr->way[0]->changeCount != fsDeter - 3 && ptr->way[0]->changeCount != fsDeter - 4 && ptr->way[0]->changeCount != fsDeter - 5 && ptr->way[0]->changeCount != fsDeter - 6)
//                                    ptr = ptr->way[0];
//                                else if (ptr->way[1] && ptr->way[1]->changeCount != fsDeter && ptr->way[1]->changeCount != fsDeter - 1 && ptr->way[1]->changeCount != fsDeter - 2 && ptr->way[1]->changeCount != fsDeter - 3 && ptr->way[1]->changeCount != fsDeter - 4 && ptr->way[1]->changeCount != fsDeter - 5 && ptr->way[1]->changeCount != fsDeter - 6)
//                                    ptr = ptr->way[1];
//                                else
//                                    break;
//                                int tfFirstDeter = fsDeter + 1;
//                                firstSearchCount++;
//                                int firstTransfer = First_Search_Trans(firstList, firstSearchCount, tfFirstDeter);
//                                if (firstTransfer == 0)
//                                {
//                                    ptr = tfTempFs1;
//                                }
//                                else if (firstTransfer == 1)
//                                {
//                                    return;
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//            ptr = tfTempFs;
//        }
//        if (ptr->way[1] && ptr->way[1]->changeCount != fsDeter && ptr->way[1]->changeCount != fsDeter - 1 && ptr->way[1]->changeCount != fsDeter - 2 && ptr->way[1]->changeCount != fsDeter - 3 && ptr->way[1]->changeCount != fsDeter - 4 && ptr->way[1]->changeCount != fsDeter - 5 && ptr->way[1]->changeCount != fsDeter - 6)
//            ptr = ptr->way[1];
//        else
//            return;
//    }
//}
//
//int First_Search_Trans(char firstList[], int firstSearchCount, int fsDeter)
//{
//    struct SUBWAY* tfTempFs;
//    struct SUBWAY* tfTempFs1;
//    struct SUBWAY* tfTemp;
//    tfTemp = ptr;
//    while (ptr)
//    {
//        ptr->changeCount = fsDeter;
//        if (strcmp(ptr->list, firstList) == 0)
//            return 1;
//        if (ptr->change != 0 && firstSearchCount < 7)
//        {
//            tfTempFs = ptr;
//            for (int i = 0; i < 100; i++)
//            {
//                if (strcmp(transSearchList[i].list, ptr->list) == 0)
//                {
//                    for (int j = 0; j < 6; j++)
//                    {
//                        if (transSearchList[i].transLine[j] != ptr->transNum && transSearchList[i].transLine[j] != 0)
//                        {
//                            ptr = transSearchList[i].transWay[j];
//                            //ptr->changeCount = fsDeter + 1;
//                            tfTempFs1 = ptr;
//                            for (int tf1 = 0; tf1 < 2; tf1++)
//                            {
//                                if (ptr->way[0] && ptr->way[0]->changeCount != fsDeter && ptr->way[0]->changeCount != fsDeter - 1 && ptr->way[0]->changeCount != fsDeter - 2 && ptr->way[0]->changeCount != fsDeter - 3 && ptr->way[0]->changeCount != fsDeter - 4 && ptr->way[0]->changeCount != fsDeter - 5 && ptr->way[0]->changeCount != fsDeter - 6)
//                                    ptr = ptr->way[0];
//                                else if (ptr->way[1] && ptr->way[1]->changeCount != fsDeter && ptr->way[1]->changeCount != fsDeter - 1 && ptr->way[1]->changeCount != fsDeter - 2 && ptr->way[1]->changeCount != fsDeter - 3 && ptr->way[1]->changeCount != fsDeter - 4 && ptr->way[1]->changeCount != fsDeter - 5 && ptr->way[1]->changeCount != fsDeter - 6)
//                                    ptr = ptr->way[1];
//                                else
//                                    break;
//                                int tfFirstDeter = fsDeter + 1;
//                                firstSearchCount++;
//                                int firstTransfer = First_Search_Trans(firstList, firstSearchCount, tfFirstDeter);
//                                if (firstTransfer == 0)
//                                {
//                                    ptr = tfTempFs1;
//                                }
//                                else if (firstTransfer == 1)
//                                {
//                                    return 1;
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//            ptr = tfTempFs;
//        }
//        if (ptr->way[0] && ptr->way[0]->changeCount != fsDeter && ptr->way[0]->changeCount != fsDeter - 1 && ptr->way[0]->changeCount != fsDeter - 2 && ptr->way[0]->changeCount != fsDeter - 3 && ptr->way[0]->changeCount != fsDeter - 4 && ptr->way[0]->changeCount != fsDeter - 5 && ptr->way[0]->changeCount != fsDeter - 6)
//            ptr = ptr->way[0];
//        else if (ptr->way[1] && ptr->way[1]->changeCount != fsDeter && ptr->way[1]->changeCount != fsDeter - 1 && ptr->way[1]->changeCount != fsDeter - 2 && ptr->way[1]->changeCount != fsDeter - 3 && ptr->way[1]->changeCount != fsDeter - 4 && ptr->way[1]->changeCount != fsDeter - 5 && ptr->way[1]->changeCount != fsDeter - 6)
//            ptr = ptr->way[1];
//        else
//            return 0;
//    }
//}
