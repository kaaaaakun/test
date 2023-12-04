#include <stdio.h>

#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

int main()
{
    int fd1=open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NONBLOCK);
    fcntl(fd1, F_SETFL,0);
    //load configuration
    struct termios conf_tio;
    tcgetattr(fd1,&conf_tio);
    //set baudrate
    speed_t BAUDRATE = 1000000;
    cfsetispeed(&conf_tio, BAUDRATE);
    cfsetospeed(&conf_tio, BAUDRATE);
    //non canonical, non echo back
    conf_tio.c_lflag &= ~(ECHO | ICANON);
    //non blocking
    conf_tio.c_cc[VMIN]=0;
    conf_tio.c_cc[VTIME]=0;
    //store configuration
    tcsetattr(fd1,TCSANOW,&conf_tio);

    write(fd1,"#;",2);
    printf("Bytes sent\n");

    sleep(1);

    char buff[100]="=======================";
    int rd=read(fd1,buff,sizeof(buff));
    printf("Bytes sent are %s\n",buff);
    printf("rd:%d\n",rd);
    close(fd1);
    return 0;
}
