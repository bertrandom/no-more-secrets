/*
 * Copyright (c) 2017 Brian Barto
 * 
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GPL License. See LICENSE for more details.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include "nmseffect.h"

int main(void) {
	int termCols, spaces, spaces1, spaces2, spaces3 = 0;
	unsigned char *display_uc = NULL;
	char *display        = NULL;
	char *head1Left      = "Syscon node: bx-456";
	char *head1Middle1   = "Falc=34";
	char *head1Middle2   = "HP: 57";
	char *head1Right     = "Authorization Code: 23-3456";
	char *head2Left      = "DATANET PROC RECORD:  45-3456-W-3452";
	char *head2Right     = "Transnet on/xc-3";
	char *head3Center    = "FEDERAL RESERVE TRANSFER NODE";
	char *head4Center    = "National Headquarters";
	char *head5Center    = "************  Remote Systems Network Input Station  ************";
	char *head6Center    = "================================================================";
	char *menu1          = "[1] Interbank Funds Transfer  (Code Prog: 485-GWU)";
	char *menu2          = "[2] International Telelink Access  (Code Lim: XRP-262)";
	char *menu3          = "[3] Remote Facsimile Send/Receive  (Code Tran:  2LZP-517)";
	char *menu4          = "[4] Regional Bank Interconnect  (Security Code:  47-B34)";
	char *menu5          = "[5] Update System Parameters  (Entry Auth. Req.)";
	char *menu6          = "[6] Remote Operator Logon/Logoff";
	char *foot1Center    = "================================================================";
	char *foot2Center    = "[ ] Select Option or ESC to Abort";
	char *foot3Left      = "  SYSTEM DATALINK NODE:  GY-3-A345";
	char *foot3Right     = "TRANSCOM FIELD:  ACTIVE";

	// Get terminal dimentions (needed for centering)
	struct winsize w;
    // if not an interactive tty, w is not populated, resulting in UB
	if (ioctl(0, TIOCGWINSZ, &w) == -1) {
        perror("Input not from an interactive terminal");
        return 1;
    }
	termCols = w.ws_col;

	// Allocate space for our display string
	if ((display = malloc(20 * termCols)) == NULL)
	{
		fprintf(stderr, "Memory Allocation Error. Quitting!\n");
		return 1;
	}

	// Allocate space for our display string
	if ((display_uc = malloc(20 * termCols)) == NULL)
	{
        free(display);
		fprintf(stderr, "Memory Allocation Error. Quitting!\n");
		return 1;
	}

	memset(display, 0, 20 * termCols);
	memset(display_uc, 0, 20 * termCols);

	// Start building the display string
	strcpy(display, head1Left);

	spaces = termCols - strlen(head1Left) - strlen(head1Middle1) - strlen(head1Middle2) - strlen(head1Right);
	spaces1 = (spaces / 3) - 1;
	spaces2 = spaces1;
	spaces3 = spaces - spaces1 - spaces2;

	while (spaces1 > 0) {
		strcat(display, " ");
		--spaces1;
	}
	strcat(display, head1Middle1);

	while (spaces2 > 0) {
		strcat(display, " ");
		--spaces2;
	}
	strcat(display, head1Middle2);

	while (spaces3 > 0) {
		strcat(display, " ");
		--spaces3;
	}
	strcat(display, head1Right);

	strcat(display, "\n");

	strcat(display, head2Left);

	spaces = termCols - strlen(head2Left) - strlen(head2Right);
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, head2Right);

	strcat(display, "\n");
	strcat(display, "\n");

	spaces = (termCols - strlen(head3Center)) / 2;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, head3Center);

	strcat(display, "\n");
	strcat(display, "\n");

	spaces = (termCols - strlen(head4Center)) / 2;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, head4Center);

	strcat(display, "\n");
	strcat(display, "\n");

	spaces = (termCols - strlen(head5Center)) / 2;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, head5Center);

	strcat(display, "\n");

	spaces = (termCols - strlen(head6Center)) / 2;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, head6Center);

	strcat(display, "\n");
	strcat(display, "\n");

	spaces = ((termCols - strlen(head6Center)) / 2) + 3;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, menu1);

	strcat(display, "\n");

	spaces = ((termCols - strlen(head6Center)) / 2) + 3;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, menu2);

	strcat(display, "\n");

	spaces = ((termCols - strlen(head6Center)) / 2) + 3;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, menu3);

	strcat(display, "\n");

	spaces = ((termCols - strlen(head6Center)) / 2) + 3;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, menu4);

	strcat(display, "\n");

	spaces = ((termCols - strlen(head6Center)) / 2) + 3;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, menu5);

	strcat(display, "\n");

	spaces = ((termCols - strlen(head6Center)) / 2) + 3;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, menu6);

	strcat(display, "\n");
	strcat(display, "\n");

	spaces = (termCols - strlen(foot1Center)) / 2;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, foot1Center);

	strcat(display, "\n");
	strcat(display, "\n");

	spaces = (termCols - strlen(foot2Center)) / 2 + 1;
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, foot2Center);

	strcat(display, "\n");
	strcat(display, "\n");

	strcat(display, foot3Left);

	spaces = termCols - strlen(foot3Left) - strlen(foot3Right);
	while (spaces > 0) {
		strcat(display, " ");
		--spaces;
	}
	strcat(display, foot3Right);

	nmseffect_set_clearscr(1);

	memcpy(display_uc, display, 20 * termCols);

	// Execute effect
	nmseffect_exec(display_uc, strlen(display));

	free(display);
	free(display_uc);

	return 0;
}
