#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <syslog.h>


int main(int argc, char *argv[]) {
    char *path;
    char *msg;
    openlog(NULL, 0, LOG_USER);

    if (argc != 3) {
        printf("Missing parameters\n");
		syslog(LOG_ERR, "Invalid Number of arguments: %d", argc);
        return 1;
    } else {
       path = argv[1];
       msg = argv[2];
    }

    int fd = open(path, O_RDWR | O_CREAT, 0644);
	if (fd == -1 ) {
		printf("opening error..");
		syslog(LOG_ERR, "Error opening file.");
	}

	size_t textLength = strlen(msg);
	size_t written = write(fd, msg, textLength);
	if (written == -1 ) {
		printf("writing eror..");
		syslog(LOG_ERR, "Error writing to file.");
	} else {
		syslog(LOG_DEBUG, "Writing '%s' to %s where '%s' is the text string written to file (second argument) and %s is the file created by the script.", msg, path, msg, path);
    }
	close(fd);
	return 0;
}
