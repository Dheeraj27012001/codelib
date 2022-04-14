
int countBitsFlip(int a, int b)
{
    int count = 0;
    int last_a, last_b;

    while ((a) || (b))
    {

        last_a = (a & 1);
        last_b = (b & 1);

        if ((last_a ^ last_b))
        {
            count++;
        }

        a = a >> 1;
        b = b >> 1;
    }

    return count;
}
