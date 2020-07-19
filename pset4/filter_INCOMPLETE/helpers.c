#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Cap value at 255
int cap(int n)
{
    if (n > 255)
    {
        n = 255;
    }

    return n;
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float r = image[j][i].rgbtRed;
            float g = image[j][i].rgbtGreen;
            float b = image[j][i].rgbtBlue;

            float avg = round((r + g + b) / 3.0);

            image[j][i].rgbtRed = avg;
            image[j][i].rgbtGreen = avg;
            image[j][i].rgbtBlue = avg;

        }
    }
    return;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{



    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float r = image[j][i].rgbtRed;
            float g = image[j][i].rgbtGreen;
            float b = image[j][i].rgbtBlue;


            image[j][i].rgbtRed = cap(round(.393 * r + .769 * g + .189 * b));
            image[j][i].rgbtGreen = cap(round(.349 * r + .686 * g + .168 * b));
            image[j][i].rgbtBlue = cap(round(.272 * r + .534 * g + .131 * b));

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int temp[3] = {image[i][j].rgbtRed, image[i][j].rgbtGreen, image[i][j].rgbtBlue};


            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            image[i][width - j - 1].rgbtRed = temp[0];
            image[i][width - j - 1].rgbtGreen = temp[1];
            image[i][width - j - 1].rgbtBlue = temp[2];
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    //float r[9];
    //float g[9];
    //float b[9];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            //r[0] = image[j-1][i-1].rgbtRed;
            //r[1] = image[j][i-1].rgbtRed;
            //r[2] = image[j+1][i-1].rgbtRed;
            //r[3] = image[j-1][i].rgbtRed;
            //r[4] = image[j][i].rgbtRed;
            //r[5] = image[j+1][i].rgbtRed;
            //r[6] = image[j-1][i+1].rgbtRed;
            //r[7] = image[j][i+1].rgbtRed;
            //r[8] = image[j+1][i+1].rgbtRed;

            //image[j][i].rgbtRed = round((r[0] + r[1] + r[2] + r[3]+ r[4] + r[5] + r[6] + r[7] + r[8] ) / 9.0);

            //g[0] = image[j-1][i-1].rgbtGreen;
            //g[1] = image[j][i-1].rgbtGreen;
            //g[2] = image[j+1][i-1].rgbtGreen;
            //g[3] = image[j-1][i].rgbtGreen;
            //g[4] = image[j][i].rgbtGreen;
            //g[5] = image[j+1][i].rgbtGreen;
            //g[6] = image[j-1][i+1].rgbtGreen;
            //g[7] = image[j][i+1].rgbtGreen;
            //g[8] = image[j+1][i+1].rgbtGreen;

            //image[j][i].rgbtGreen = round((g[0] + g[1] + g[2] + g[3]+ g[4] + g[5] + g[6] + g[7] + g[8] ) / 9.0);

            //b[0] = image[j-1][i-1].rgbtBlue;
            //b[1] = image[j][i-1].rgbtBlue;
            //b[2] = image[j+1][i-1].rgbtBlue;
            //b[3] = image[j-1][i].rgbtBlue;
            //b[4] = image[j][i].rgbtBlue;
            //b[5] = image[j+1][i].rgbtBlue;
            //b[6] = image[j-1][i+1].rgbtBlue;
            //b[7] = image[j][i+1].rgbtBlue;
            //b[8] = image[j+1][i+1].rgbtBlue;

            //image[j][i].rgbtBlue = round((b[0] + b[1] + b[2] + b[3]+ b[4] + b[5] + b[6] + b[7] + b[8] ) / 9.0);

        }
    }
    return;
}
