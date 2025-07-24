#include <unistd.h>

void ft_print_numbers(void)
{
    static const char nums[] = "0123456789";
    /* writes all 10 characters at once */
    write(1, nums, sizeof(nums) - 1);
}
