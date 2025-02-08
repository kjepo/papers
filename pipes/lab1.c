#include <unistd.h>
#include <stdlib.h>

#define STDIN 0
#define STDOUT 1
#define STDERR 2
#define READ 0
#define WRITE 1
#define CHILD 0
#define NEWLINE '\n'
#define OK 0
#define ERROR 1

int main() {
  int p1[2], p2[2];		/* two pipes, each with two ends */
  char buf[1];

  if (pipe(p1) || pipe(p2)) {	/* create two pipes */
    write(STDERR, "Couldn't pipe\n", 14);
    exit(ERROR);
  }

  if (fork() == CHILD) {	/* this becomes process 1 */
    close(STDOUT);
    close(p1[READ]);
    close(p2[READ]);
    close(p2[WRITE]);
    while (read(STDIN, buf, 1)) {
      if (buf[0] == NEWLINE)
	buf[0] = ' ';
      write(p1[WRITE], buf, 1);
    }
    close(STDIN);
    close(p1[WRITE]);
    exit(OK);
  } else if (fork() == CHILD) {	/* this becomes process 2 */
    close(STDIN);
    close(STDOUT);
    close(p1[WRITE]);
    close(p2[READ]);
    while (read(p1[READ], buf, 1)) {
      if (buf[0] != ' ')
	write(p2[WRITE], buf, 1);
    }
    close(p1[READ]);
    close(p2[WRITE]);
    exit(OK);
  } else {			/* parent continues here and becomes process 3 */
    close(STDIN);
    close(p1[READ]);
    close(p1[WRITE]);
    close(p2[WRITE]);
    int n;
    while (read(p2[READ], buf, 1)) {
      if (('a' <= buf[0]) && (buf[0] <= 'z'))
	buf[0] -= 32;
      write(STDOUT, buf, 1);
    }
    close(p2[READ]);
    close(STDOUT);
    exit(OK);
  }
}
