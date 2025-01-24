#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_STRING_LEN 1024


bool read_line(char *line, int length)
{
    int i = 0;
    while (i < length)
    {
        if(scanf("%c", line + i) == EOF)
        {
            return true;
        }
        if(line[i] == '\n')
        {
            return true;
        }
        i++;
    }
    return false;
}
bool string_copy(char *target, int length, char *src)
{
    for (int i = 0; i < length; i++)
    {
        target[i] = src[i];
        if(src[i] == '\0')
        {
            return true;
        }
    }
    return false;
}



int letCnt(char* sentence)
{
    int cnt = 0;
    while (*sentence++ != '\0')
    {
        cnt++;
    }
    return cnt;
}


int spaceCnt(char* sentence)
{
    int cnt = 0;
    while(*sentence++ == ' ')// b
    {
        cnt++;
    }
    return cnt;
}
int wordsCnt(char* sentence)
{
    int  cnt = *sentence != ' ';

    while (*sentence++ != '\0')
    {
        if(spaceCnt(sentence) != 0)
        {
            cnt++;
        }
        sentence += spaceCnt(sentence);
    }
    return cnt;
}


int vowelCnt(char* sentence)
{
    int cnt = 0;
    while (*sentence++ != '\0')
    {
        if( *sentence == 'a' || *sentence == 'A' || *sentence == 'e'
            || *sentence == 'E' ||
            *sentence == 'i' || *sentence == 'I' || *sentence == 'o'
            || *sentence == 'O' ||
            *sentence == 'u' || *sentence == 'U')
        {
            cnt++;
        }
    }
    return cnt;

}


int analyze_sentence(char* sentence, char* operation)
{
    if(!strcmp(operation,"length"))
    {
       return  letCnt(sentence);
    }
    if(!strcmp(operation,"words"))
    {
        return wordsCnt(sentence);
    }
    if(!strcmp(operation,"vowels"))
    {
        return vowelCnt(sentence);
    }
return 0;
}


// Those functions are not ready, they can now the length of the shortest word
// But we need not only the length, we also need the exact word,
int letInWordCnt(char *sentence)
{
    int cnt = 0;
    while(*sentence++ != ' ')
    {
        cnt++;
    }
}
int findShortest(char *sentence, char *word)
{
    int min = MAX_STRING_LEN, cntL;

    while (*sentence++ != '\n')
    {
        cntL = letInWordCnt(sentence);
        if(min > cntL)
        {
            min = cntL;
        }
        sentence += spaceCnt(sentence);
    }

    return min;
}
void get_word(char *sentence, char *word, bool shortest)
{
    if(shortest)
    {

    }




}




int main()
{
    char line[MAX_STRING_LEN] = "";

    printf("Enter a string to be analyzed: ");
    if (read_line(line, sizeof(line)) == false) {
        return -1; // failed to read a line
    }

    int line_length = analyze_sentence(line, "length");
    int num_words = analyze_sentence(line, "words");
    int num_vowels = analyze_sentence(line, "vowels");
    printf("The length of the sentence \"%s\"", line);
    printf(" is %d.\nIt has %d words and %d vowels.\n"
        , line_length, num_words, num_vowels);
}
