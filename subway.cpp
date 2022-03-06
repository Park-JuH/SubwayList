//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//struct SUBWAY
//{
//    char list[100];
//    struct SUBWAY* way[6];
//    int change = 0;
//};
//
//struct WAY
//{
//    char way[100];
//}subway[100];
//
//bool Read_file(const char fname[], struct SUBWAY* head, struct SUBWAY* first);
//void Plus_subway(char fname[]);
//void Search_list(char firstList[], char secondList[]);
//int Transfer(char firstList[], char secondList[], int c3, int transCount);
//void First_Search(char firstList[], int firstSearchCount);
//
//struct SUBWAY* ptr = NULL;
//struct SUBWAY* prev;
//char subwayList[100][100][100];
//int global_c[200] = { 0, }, global_cCount = 0;
//int wayCount = 0;
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
//    int size = 0;
//    while (ptr)
//    {
//        if (ptr->change != 0)
//        {
//            if (size == 0 && strcmp(ptr->list, "Sindorim") == 0)
//            {
//                plusTemp = ptr;
//                strcpy(fname, "one.txt");
//                Plus_subway(fname);
//                size++;
//                ptr = plusTemp;
//            }
//            else if (size == 1 && strcmp(ptr->list, "Yeongdeungpo-guOffice") == 0)
//            {
//                plusTemp = ptr;
//                strcpy(fname, "five.txt");
//                Plus_subway(fname);
//                ptr = plusTemp;
//                size++;
//            }
//            else if (size == 2 && strcmp(ptr->list, "Dangsan") == 0)
//            {
//                plusTemp = ptr;
//                strcpy(fname, "nine.txt");
//                Plus_subway(fname);
//                ptr = plusTemp;
//                size++;
//            }
//            else if (size == 3 && strcmp(ptr->list, "Hapjeong") == 0)
//            {
//                plusTemp = ptr;
//                strcpy(fname, "six.txt");
//                Plus_subway(fname);
//                ptr = plusTemp;
//                size++;
//            }
//            else if (size == 4 && strcmp(ptr->list, "Euljiro3-ga") == 0)
//            {
//                plusTemp = ptr;
//                strcpy(fname, "three.txt");
//                Plus_subway(fname);
//                ptr = plusTemp;
//                size++;
//            }
//            else if (size == 5 && strcmp(ptr->list, "DongdaemunHistory&CulturePark") == 0)
//            {
//                plusTemp = ptr;
//                strcpy(fname, "four.txt");
//                Plus_subway(fname);
//                ptr = plusTemp;
//                size++;
//            }
//            else if (size == 6 && strcmp(ptr->list, "Daerim") == 0)
//            {
//                plusTemp = ptr;
//                strcpy(fname, "seven.txt");
//                Plus_subway(fname);
//                ptr = plusTemp;
//                size++;
//            }
//        }
//        if (strcmp(ptr->list, "Daerim") == 0)
//            break;
//        ptr = ptr->way[0];
//    }
//    ptr = head->way[0];
//    printf("\n\n");
//    ptr = head->way[0];
//    printf("START: ");
//    gets_s(firstList, sizeof(firstList));
//    printf("END: ");
//    gets_s(secondList, sizeof(secondList));
//    int searchCount = 0;
//    int firstSearchCount = 0;
//    First_Search(firstList, firstSearchCount);
//    int wayCount = 0;
//    Search_list(firstList, secondList);
//
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
//        }
//        if (strcmp(node->list, "Daerim") == 0)
//        {
//            first->way[1] = node; //20220124 node, &node의 차이
//            node->way[0] = first;
//            node->way[1] = ptr;
//            ptr->way[0] = node;
//            node->change = 0;
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
//            ptr->way[2] = node;
//            node->way[3] = ptr;
//            node->change = 9;
//
//        }
//        else
//        {
//            ptr->way[0] = node;
//            node->way[1] = ptr;
//            node->change = 0;
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
//        ptr = node;
//        nodeTemp = node;
//        i++;
//    }
//    ptr = temp;
//    while (ptr)
//    {
//        if (strcmp(ptr->list, "CityHall") == 0 && strcmp(fname, "one.txt") == 0)
//        {
//            ptr->way[2] = nodeTemp;
//            ptr->change = 1;
//            nodeTemp->way[3] = ptr;
//            nodeTemp->change = 9;
//            break;
//        }
//        else if (strcmp(ptr->list, "Chungjeongno") == 0 && strcmp(fname, "five.txt") == 0)
//        {
//            ptr->way[2] = nodeTemp;
//            ptr->change = 1;
//            nodeTemp->way[3] = ptr;
//            nodeTemp->change = 9;
//            break;
//        }
//        else if (strcmp(ptr->list, "SeoulNat'lUniv.ofEducation") == 0 && strcmp(fname, "three.txt") == 0)
//        {
//            ptr->way[2] = nodeTemp;
//            ptr->change = 1;
//            nodeTemp->way[3] = ptr;
//            nodeTemp->change = 9;
//            break;
//        }
//        else if (strcmp(ptr->list, "Sadang") == 0 && strcmp(fname, "four.txt") == 0)
//        {
//            ptr->way[2] = nodeTemp;
//            ptr->change = 1;
//            nodeTemp->way[3] = ptr;
//            nodeTemp->change = 9;
//            break;
//        }
//        else if (strcmp(ptr->list, "KonkukUniv.") == 0 && strcmp(fname, "seven.txt") == 0)
//        {
//            ptr->way[2] = nodeTemp;
//            ptr->change = 1;
//            nodeTemp->way[3] = ptr;
//            nodeTemp->change = 9;
//            break;
//        }
//        else if (strcmp(ptr->list, "Sindang") == 0 && strcmp(fname, "six.txt") == 0)
//        {
//            ptr->way[2] = nodeTemp;
//            ptr->change = 1;
//            nodeTemp->way[3] = ptr;
//            nodeTemp->change = 9;
//            break;
//        }
//        else if (strcmp(ptr->list, "SportsComplex") == 0 && strcmp(fname, "nine.txt") == 0)
//        {
//            ptr->way[2] = nodeTemp;
//            ptr->change = 1;
//            nodeTemp->way[3] = ptr;
//            nodeTemp->change = 9;
//            break;
//        }
//        ptr = ptr->way[0];
//    }
//    fclose(pfile);
//    return;
//}
//
////Search subway
//void Search_list(char firstList[], char secondList[])
//{
//    //Transfer를 합쳐버릴까?
//    //Transfer시, way를 어떤 기준으로 계속 판단할 것인가?
//    int c1 = 0, c2 = 0;
//    int changeCt = 0;
//    struct SUBWAY* tfTemp1;
//    struct SUBWAY* tfTemp2;
//    struct SUBWAY* firstTemp = NULL;
//    int fIndex, sIndex, tfC1, tfC2, transCount = 0;
//    firstTemp = ptr;
//    subwayChange = 0;
//    while (ptr)
//    {
//        if (global_cCount > 25)
//            break;
//        strcpy(subwayList[global_cCount][c1], ptr->list);
//        if (strcmp(ptr->list, secondList) == 0 || c1 >= 50)
//            break;
//        if (ptr->change != 0)
//        {
//            tfTemp1 = ptr;
//            tfC1 = c1;
//            if (ptr->change == 9)
//            {
//                ptr = ptr->way[3];
//                tfTemp1 = ptr;
//                tfC1 = c1;
//                strcpy(transList, ptr->list);
//                int transfer = Transfer(firstList, secondList, c1, transCount);
//                if (transfer == 0)
//                {
//                    for (int q = c1 + 1; q <= 50; q++)
//                    {
//                        for (int p = 0; p <= 100; p++)
//                            subwayList[global_cCount][q][p] = '\0';
//                    }
//                    ptr = tfTemp1;
//                    c1 = tfC1;
//                }
//                else
//                {
//                    global_c[global_cCount] = transfer;
//                    global_cCount++;
//                    ptr = tfTemp1;
//                    c1 = tfC1;
//                    for (int q = 0; q <= c1; q++)
//                        strcpy(subwayList[global_cCount][q], subwayList[global_cCount - 1][q]);
//                }
//            }
//            else
//            {
//                if (transCount >= 5)
//                {
//                    ptr = ptr->way[subwayChange];
//                    c1++;
//                    continue;
//                }
//                int tempChange1;
//                int tfCount = 0;
//                for (tfCount = 0; tfCount < ptr->change; tfCount++)
//                {
//                    tempChange1 = tfTemp1->change;
//                    if (tfCount == 0)
//                        ptr = ptr->way[2];
//                    /*else if (tfCount == 1)
//                        ptr = ptr->way[4];*/
//                    strcpy(transList, ptr->list);
//                    int transfer = Transfer(firstList, secondList, c1, transCount);
//                    transCount++;
//                    if (transfer == 0)
//                    {
//                        for (int q = c1 + 1; q <= 50; q++)
//                        {
//                            for (int p = 0; p <= 100; p++)
//                                subwayList[global_cCount][q][p] = '\0';
//                        }
//                        ptr = tfTemp1;
//                        c1 = tfC1;
//                    }
//                    else if (transfer == 100)
//                    {
//                        for (int q = 0; q <= 50; q++)
//                        {
//                            for (int p = 0; p <= 100; p++)
//                                subwayList[global_cCount][q][p] = '\0';
//                        }
//                        globalSubwayCount++;
//                        break;
//                    }
//                    else
//                    {
//                        global_c[global_cCount] = transfer;
//                        global_cCount++;
//                        ptr = tfTemp1;
//                        c1 = tfC1;
//                        for (int q = 0; q <= c1; q++)
//                            strcpy(subwayList[global_cCount][q], subwayList[global_cCount - 1][q]);
//                    }
//                }
//            }
//        }
//        if (ptr->way[0])
//            ptr = ptr->way[0];
//        else
//            break;
//        c1++;
//    }
//    fIndex = global_cCount;
//    global_cCount++;
//    ptr = firstTemp;
//    wayCount++;
//    transCount = 0;
//    //Another
//    subwayChange = 1;
//    while (ptr)
//    {
//        if (global_cCount > 50)
//            break;
//        strcpy(subwayList[global_cCount][c2], ptr->list);
//        if (strcmp(ptr->list, secondList) == 0 || c2 >= 50)
//            break;
//        if (ptr->change != 0)
//        {
//            tfTemp2 = ptr;
//            tfC2 = c2;
//            if (ptr->change == 9)
//            {
//                ptr = ptr->way[3];
//                tfTemp2 = ptr;
//                tfC2 = c2;
//                strcpy(transList, ptr->list);
//                int transfer = Transfer(firstList, secondList, c2, transCount);
//                if (transfer == 0)
//                {
//                    for (int q = c2 + 1; q <= 50; q++)
//                    {
//                        for (int p = 0; p <= 100; p++)
//                            subwayList[global_cCount][q][p] = '\0';
//                    }
//                    ptr = tfTemp2;
//                    c2 = tfC2;
//                }
//                else
//                {
//                    global_c[global_cCount] = transfer;
//                    global_cCount++;
//                    ptr = tfTemp2;
//                    c2 = tfC2;
//                    for (int q = 0; q <= c2; q++)
//                        strcpy(subwayList[global_cCount][q], subwayList[global_cCount - 1][q]);
//                }
//            }
//            else
//            {
//                if (transCount >= 5)
//                {
//                    ptr = ptr->way[subwayChange];
//                    c2++;
//                    continue;
//                }
//                int tempChange2;
//                int tfCount = 0;
//                for (tfCount = 0; tfCount < ptr->change; tfCount++)
//                {
//                    tempChange2 = tfTemp2->change;
//                    if (tfCount == 0)
//                        ptr = ptr->way[2];
//                    /*else if (tfCount == 1)
//                        ptr = ptr->way[4];*/
//                    strcpy(transList, ptr->list);
//                    int transfer = Transfer(firstList, secondList, c2, transCount);
//                    transCount++;
//                    if (transfer == 0)
//                    {
//                        for (int q = c2 + 1; q <= 50; q++)
//                        {
//                            for (int p = 0; p <= 100; p++)
//                                subwayList[global_cCount][q][p] = '\0';
//                        }
//                        ptr = tfTemp2;
//                        ptr->change = tempChange2;
//                        c2 = tfC2;
//                    }
//                    else
//                    {
//                        global_c[global_cCount] = transfer;
//                        global_cCount++;
//                        ptr = tfTemp2;
//                        ptr->change = tempChange2;
//                        c2 = tfC2;
//                        for (int q = 0; q <= c2; q++)
//                            strcpy(subwayList[global_cCount][q], subwayList[global_cCount - 1][q]);
//                    }
//                }
//            }
//        }
//        if (ptr->way[1])
//            ptr = ptr->way[1];
//        else
//            break;
//        c2++;
//    }
//    sIndex = global_cCount;
//    int x = 0;
//    printf("\n\nBEST WAY\n");
//    //Compare
//    int min;
//    int minIndex;
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
//
//    return;
//}
//
//int Transfer(char firstList[], char secondList[], int c3, int transCount)
//{
//    int tfChange = 0;
//    int tfC3;
//    int tempSubwayChange;
//    struct SUBWAY* tfTemp3;
//    c3++;
//    while (ptr)
//    {
//        strcpy(subwayList[global_cCount][c3], ptr->list);
//        if (strcmp(ptr->list, secondList) == 0)
//            return c3;
//        else if (strcmp(ptr->list, firstList) == 0 || c3 >= 50)
//            return 0;
//        if (ptr->change != 0)
//        {
//            if (ptr->change == 9)
//            {
//                if (strcmp(ptr->list, transList) == 0)
//                {
//                    if (ptr->way[0] == NULL)
//                    {
//                        ptr = ptr->way[1];
//                        tempSubwayChange = subwayChange;
//                        subwayChange = 1;
//                        c3++;
//                        continue;
//                    }
//                    else
//                    {
//                        ptr = ptr->way[0];
//                        tempSubwayChange = subwayChange;
//                        subwayChange = 0;
//                        c3++;
//                        continue;
//                    }
//                }
//                else
//                {
//                    ptr = ptr->way[3];
//                    tfTemp3 = ptr;
//                    tfC3 = c3;
//                    tempSubwayChange = subwayChange;
//                    strcpy(transList, ptr->list);
//                    int transfer = Transfer(firstList, secondList, c3, transCount);
//                    if (transfer == 0)
//                    {
//                        for (int q = c3 + 1; q <= 50; q++)
//                        {
//                            for (int p = 0; p <= 100; p++)
//                                subwayList[global_cCount][q][p] = '\0';
//                        }
//                        ptr = tfTemp3;
//                        c3 = tfC3;
//                    }
//                    else if (transfer == 100)
//                        return 100;
//                    else
//                    {
//                        global_c[global_cCount] = transfer;
//                        global_cCount++;
//                        if (global_cCount > 25 && globalSubwayCount == 0)
//                            return 100;
//                        else if (global_cCount > 50 && globalSubwayCount == 1)
//                            return 100;
//                        ptr = tfTemp3;
//                        c3 = tfC3;
//                        for (int q = 0; q <= c3; q++)
//                            strcpy(subwayList[global_cCount][q], subwayList[global_cCount - 1][q]);
//                    }
//                }
//            }
//            else
//            {
//                if (strcmp(transList, ptr->list) == 0)
//                {
//                    ptr = ptr->way[subwayChange];
//                    c3++;
//                    continue;
//                }
//                else
//                {
//                    if (transCount >= 5)
//                    {
//                        ptr = ptr->way[subwayChange];
//                        c3++;
//                        continue;
//                    }
//                    int tempChange3;
//                    tempChange3 = ptr->change;
//                    ptr->change = 0;
//                    tfC3 = c3;
//                    tfTemp3 = ptr;
//                    tempSubwayChange = subwayChange;
//                    ptr = ptr->way[2];
//                    strcpy(transList, ptr->list);
//                    int transfer = Transfer(firstList, secondList, c3, transCount);
//                    transCount++;
//                    if (transfer == 0)
//                    {
//                        for (int q = c3 + 1; q <= 50; q++)
//                        {
//                            for (int p = 0; p <= 100; p++)
//                                subwayList[global_cCount][q][p] = '\0';
//                        }
//                        ptr = tfTemp3;
//                        ptr->change = tempChange3;
//                        c3 = tfC3;
//                    }
//                    else
//                    {
//                        global_c[global_cCount] = transfer;
//                        global_cCount++;
//                        if (global_cCount > 25 && globalSubwayCount == 0)
//                        {
//                            globalSubwayCount++;
//                            return 100;
//                        }
//                        else if (global_cCount > 50 && globalSubwayCount == 1)
//                            return 100;
//                        ptr = tfTemp3;
//                        ptr->change = tempChange3;
//                        c3 = tfC3;
//                        for (int q = 0; q <= c3; q++)
//                            strcpy(subwayList[global_cCount][q], subwayList[global_cCount - 1][q]);
//                    }
//                }
//            }
//            subwayChange = tempSubwayChange;
//        }
//        if (strcmp(ptr->way[0]->list, subwayList[global_cCount][c3 - 1]) == 0 && c3 != 0)
//            subwayChange = 1;
//        else
//            subwayChange = 0;
//        ptr = ptr->way[subwayChange];
//        c3++;
//    }
//}
//
//void First_Search(char firstList[], int firstSearchCount)
//{
//    int searchCount = 0;
//    struct SUBWAY* tfTemp;
//    while (ptr)
//    {
//        if (strcmp(ptr->list, firstList) == 0)
//            return;
//        else if (searchCount >= 100)
//        {
//            return;
//        }
//        if (ptr->change != 0)
//        {
//            if (ptr->change == 9)
//            {
//                if (strcmp(ptr->list, firstTransList) == 0)
//                {
//                    if (ptr->way[0] == NULL)
//                    {
//                        ptr = ptr->way[1];
//                        subwayChange = 1;
//                        strcpy(firstSearchList, ptr->list);
//                        searchCount++;
//                        continue;
//                    }
//                    else
//                    {
//                        ptr = ptr->way[0];
//                        subwayChange = 0;
//                        strcpy(firstSearchList, ptr->list);
//                        searchCount++;
//                        continue;
//                    }
//                }
//                ptr = ptr->way[3];
//                strcpy(firstTransList, ptr->list);
//                strcpy(firstSearchList, ptr->list);
//                tfTemp = ptr;
//                First_Search(firstList, firstSearchCount);
//                if (strcmp(ptr->list, firstList) == 0 || searchCount >= 50)
//                    return;
//            }
//            else
//            {
//                if (strcmp(firstTransList, ptr->list) == 0)
//                {
//                    ptr = ptr->way[subwayChange];
//                    searchCount++;
//                    continue;
//                }
//                if (firstSearchCount >= 5)
//                {
//                    ptr = ptr->way[subwayChange];
//                    searchCount++;
//                    continue;
//                }
//                tfTemp = ptr;
//                int tfCount = 0;
//                for (tfCount = 0; tfCount < ptr->change; tfCount++)
//                {
//                    if (tfCount == 0)
//                        ptr = ptr->way[2];
//                    strcpy(firstSearchList, ptr->list);
//                    strcpy(firstTransList, ptr->list);
//                    First_Search(firstList, firstSearchCount);
//                    firstSearchCount++;
//                    if (strcmp(ptr->list, firstList) == 0 || searchCount >= 50)
//                        return;
//                }
//            }
//            ptr = tfTemp;
//            strcpy(firstSearchList, ptr->list);
//        }
//        if (strcmp(ptr->way[0]->list, firstSearchList) == 0 && searchCount != 0)
//            subwayChange = 1;
//        else
//            subwayChange = 0;
//        ptr = ptr->way[subwayChange];
//        strcpy(firstSearchList, ptr->list);
//        searchCount++;
//    }
//    if (strcmp(ptr->list, firstList) == 0)
//        return;
//    subwayChange = 1;
//    searchCount = 0;
//    while (ptr)
//    {
//        if (strcmp(ptr->list, firstList) == 0)
//            break;
//        else if (searchCount >= 100)
//        {
//            return;
//        }
//        if (ptr->change != 0)
//        {
//            if (ptr->change == 9)
//            {
//                if (strcmp(ptr->list, firstTransList) == 0)
//                {
//                    if (ptr->way[0] == NULL)
//                    {
//                        ptr = ptr->way[1];
//                        subwayChange = 1;
//                        strcpy(firstSearchList, ptr->list);
//                        searchCount++;
//                        continue;
//                    }
//                    else
//                    {
//                        ptr = ptr->way[0];
//                        subwayChange = 0;
//                        strcpy(firstSearchList, ptr->list);
//                        searchCount++;
//                        continue;
//                    }
//                }
//                ptr = ptr->way[3];
//                strcpy(firstTransList, ptr->list);
//                strcpy(firstSearchList, ptr->list);
//                tfTemp = ptr;
//                First_Search(firstList, firstSearchCount);
//                if (strcmp(ptr->list, firstList) == 0 || searchCount >= 100)
//                    break;
//            }
//            else
//            {
//                if (strcmp(firstTransList, ptr->list) == 0)
//                {
//                    ptr = ptr->way[subwayChange];
//                    searchCount++;
//                    continue;
//                }
//                if (firstSearchCount >= 5)
//                {
//                    ptr = ptr->way[subwayChange];
//                    searchCount++;
//                    continue;
//                }
//                tfTemp = ptr;
//                int tfCount = 0;
//                for (tfCount = 0; tfCount < ptr->change; tfCount++)
//                {
//                    if (tfCount == 0)
//                        ptr = ptr->way[2];
//                    strcpy(firstSearchList, ptr->list);
//                    strcpy(firstTransList, ptr->list);
//                    First_Search(firstList, firstSearchCount);
//                    firstSearchCount++;
//                    if (strcmp(ptr->list, firstList) == 0 || searchCount >= 100)
//                        break;
//                }
//            }
//            ptr = tfTemp;
//            strcpy(firstSearchList, ptr->list);
//        }
//        if (ptr->way[1])
//            subwayChange = 1;
//        else
//            subwayChange = 0;
//        ptr = ptr->way[subwayChange];
//        searchCount++;
//    }
//    if (strcmp(ptr->list, firstList) == 0)
//        return;
//}