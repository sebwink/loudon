#include <stdio.h>
#include <string.h>

#include <loudon/dlist.h>

typedef struct {
    short month, day, year;
} Date;

typedef struct {
    char title[64];
    char artist[32];
    char composer[32];
    short duration;     // in seconds
    Date published;
} Song;

const char *date_as_string(const Date *date) {
   static char str_date[12];
   sprintf(str_date, "%02d/%02d/%04d", date->month, date->day, date->year);
   return str_date;
}

void print_song(const Song *song) {
    int m = song->duration / 60;
    int s = song->duration % 60;
    printf("--------------------------------\n"
           "Title:	   %s\n"
	   "Artist:        %s\n"
	   "Composer:      %s\n"
	   "Playing time:  %d:%02d\n"
	   "Date:          %s\n",
	   song->title,
	   song->artist,
	   song->composer,
	   m, s,
	   date_as_string(&song->published));
}

int main(int argc, char **argv) {
    Song song1 = {
	"Havana Club",
	.composer = "Ottmar Liebert",
	251,
	{ 1, 1, 1998 }
    };
    Song song2 = {
	"What It Is",
	"Aubrey Haynle; Mark Knopfler",
	"Mark Knopfler",
	297,
	{ 9, 26, 2000 }
    };

    DList list;
    dlist_init(&list, NULL);
    dlist_ins_next(&list, NULL, &song1);
    dlist_ins_next(&list, list.tail, &song2);
    for (DListElmt* elmt = list.head; elmt != NULL; elmt = elmt->next)
        print_song((const Song *)elmt->data);
    
    dlist_destroy(&list);
}
