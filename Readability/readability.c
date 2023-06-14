/*
        To compile the code on mac, download clang and type:
        clang -o readability readability.c -lcs50
*/ 

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{

//read user input
    string text;
    int len = 0;
    do
    {
        text = get_string("Text: ");
        len = strlen(text);

        for (int c = 0; c < len; c++)
        {
            if (text[c] == ' ' && text[c + 1] == ' ')
            {
                len = 0;
            }
        }
    }
    while ((text[0] == ' ') || (len == 0));

//count words
    int w = 1;
    for (int i = 0; i < len; i++)
    {
        if ((text[i] == ' ') || (text[i] == '\n'))
        {
            w++;
        }
    }

//count letters
    int l = 0;
    for (int j = 0; j < len; j++)
    {
        if ((text[j] >= 'a' && text[j] <= 'z') || (text[j] >= 'A' && text[j] <= 'Z'))
        {
            l++;
        }
    }

//count sentences
    int s = 0;
    for (int k = 0; k < len; k++)
    {
        if ((text[k] == '.') || (text[k] == '?') || (text[k] == '!'))
        {
            s++;
        }
    }
    if (text[len] == '"')
    {
        s++;
    }

//letters per 100 words
    float L = (l / (float)w) * 100;

//sentences per 100 words
    float S = (s / (float)w) * 100;

//Formula: grade  = 0.0588 * L - 0.296 * S - 15.8
    float grade = 0.0588 * L - 0.296 * S - 15.8;
    grade = round(grade);
    grade = (int) grade;

//print grade
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", grade);
    }

}