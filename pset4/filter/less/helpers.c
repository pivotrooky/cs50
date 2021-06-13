#include "helpers.h"
#include <math.h>

int cap(int number);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float total = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
            float average = round(total / 3);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
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
            float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            float sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            float sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

            image[i][j].rgbtRed = cap(round(sepiaRed));
            image[i][j].rgbtGreen = cap(round(sepiaGreen));
            image[i][j].rgbtBlue = cap(round(sepiaBlue));
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        //We only have to reach the half of each row
        for (int j = 0; j < width / 2; j++)

        {
            //Any swap implementation would be okay
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Make container for original image
    RGBTRIPLE old_image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Fill original image matrix
            old_image[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int counter = 0;

            float redTotal = 0;
            float greenTotal = 0;
            float blueTotal = 0;

            //For each pixel...
            //Check to see if each possible surrounding pixel actually exists in matrix

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {

                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }

                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    //If it doesn't, then, do nothing.
                    //If it does, add their color to the corresponding variable, and increment counter;

                    redTotal += old_image[i + k][j + l].rgbtRed;
                    greenTotal += old_image[i + k][j + l].rgbtGreen;
                    blueTotal += old_image[i + k][j + l].rgbtBlue;
                    counter++;
                }
            }

            //Counter will tell us how many elements actually are included in the total of each color, so we can get the average properly.
            image[i][j].rgbtRed = round(redTotal / counter);
            image[i][j].rgbtGreen = round(greenTotal / counter);
            image[i][j].rgbtBlue = round(blueTotal / counter);
        }
    }
    return;
}

int cap(int number)
{
    if (number > 255)
    {
        return 255;
    }
    return number;
}