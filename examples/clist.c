#include <stdio.h>
#include <string.h>

#include <loudon/clist.h>

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

    CList list;
    clist_init(&list, NULL);
    clist_ins_next(&list, NULL, &song1);
    clist_ins_next(&list, list.head, &song2);
    for (struct { CListElmt* elmt; int iter_count; } loop = {list.head, 0};
         loop.iter_count < clist_size(&list);
	 loop.elmt = loop.elmt->next, ++loop.iter_count)
        print_song((const Song *)loop.elmt->data);
    
    clist_destroy(&list);
}
