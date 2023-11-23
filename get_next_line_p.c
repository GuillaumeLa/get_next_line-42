char *get_next_line(int fd)
{

}
int main()
{
    int fd = open("test.txt",O_RDONLY);
    char *test;
    test = get_next_line(fd);
    while(test)
    {
        printf("%s",test);
        test = get_next_line(fd);
    }


    return(0);
}