
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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
            line[i] = '\0';
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
    while(sentence[cnt] == ' ')
    {
        cnt++;
    }
    return cnt;
}

int wordsCnt(char* sentence)
{
    int cnt = *sentence != ' ' && *sentence != '\0';


    for(int i = 0; sentence[i] != '\0'; i++)
    {
        int spaceLen = spaceCnt(&sentence[i]);
        i += spaceLen;
        if( spaceLen != 0)
        {
            cnt++;
        }
    }
    return cnt;
}

int vowelCnt(char* sentence)
{
    int cnt = 0;
    for (int i = 0; sentence[i] != '\0'; ++i)
    {
        if (sentence[i] == 'a' || sentence[i] == 'A' || sentence[i] == 'e'
            || sentence[i] == 'E' || sentence[i] == 'i' || sentence[i] == 'I'
            || sentence[i] == 'o' || sentence[i] == 'O' || sentence[i] == 'u'
            || sentence[i] == 'U')
        {
            ++cnt;
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
int letInWordCnt(char *word)
{
    int cnt = 0;
    while(word[cnt] != ' ' && word[cnt] != '\0')
    {
        ++cnt;
    }
    return cnt;
}

void findShortest(char *sentence, char *word)
{
    int min = MAX_STRING_LEN, word_len;
    int i = 0;

    word[0] = '\0';

    while (sentence[i] != '\0')
    {
        i += spaceCnt(&sentence[i]); // jump to end of spaces
        word_len = letInWordCnt(&sentence[i]);
        if (word_len < min)
        {
            min = word_len;
            if (string_copy(word, min, &sentence[i]))
            {
                printf("failed to copy string\n");
                exit(1);
            }
            word[min] = '\0'; // end of word has to be null
        }
        i += word_len; // jump to end of word

    }
}

void findLongest(char *sentence, char *word)
{
    int max = 0, word_len;
    int i = 0;

    word[0] = '\0';



    while (sentence[i] != '\0')
    {
        word_len = letInWordCnt(&sentence[i]);
        if (word_len > max)
        {
            max = word_len;
            if (string_copy(word, max, &sentence[i]))
            {
                printf("failed to copy string\n");
                exit(1);
            }
            word[max] = '\0';
        }
        i += word_len; // jump to end of word
        i += spaceCnt(&sentence[i]); // jump to end of spaces
    }
}

void get_word(char *sentence, char *word, bool shortest)
{
    if(shortest)
    {
        findShortest(sentence, word);
    } else {
        findLongest(sentence, word);
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
    char longest_word[MAX_STRING_LEN], shortest_word[MAX_STRING_LEN];
    get_word(line, longest_word, false);
    get_word(line, shortest_word, true);

    printf("The longest word is \"%s\"\n", longest_word);
    printf("The shortest word is \"%s\"\n", shortest_word);
}
