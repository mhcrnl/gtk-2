
#include <gtk/gtk.h>

void toggle_statubar(GtkWidget *widget, gpointer statubar)
{
	if (gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM(widget)))
	{
		gtk_widget_show(statubar);
	}
	else
	{
		gtk_widget_hide(statubar);
	}
}

int main(int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *vbox;
	GtkWidget *menubar;
	GtkWidget *viewmenu;
 	GtkWidget *view;
 	GtkWidget *tog_stat;
 	GtkWidget *statusbar;

 	gtk_init(&argc, &argv);

 	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_default_size(GTK_WINDOW(window), 800, 480);

	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	gtk_window_set_title(GTK_WINDOW(window), "view statusbar");

	vbox = gtk_vbox_new(FALSE, 0);

	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();

	viewmenu = gtk_menu_new();

	view = gtk_menu_item_new_with_label("view");

	gtk_menu_item_set_submenu(GTK_MENU_ITEM(view), viewmenu);

	tog_stat = gtk_check_menu_item_new_with_label("view statusbar");

	gtk_menu_shell_append(GTK_MENU_SHELL(viewmenu), tog_stat);

	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), view);

	gtk_box_pack_end(GTK_BOX(vbox), menubar, FALSE, FALSE, 3);

	statusbar = gtk_statusbar_new();

	gtk_box_pack_end(GTK_BOX(vbox), statusbar, FALSE, TRUE, 1);
	g_signal_connect_swapped(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(G_OBJECT(tog_stat), "activate", G_CALLBACK(toggle_statubar), statusbar);
	gtk_widget_show_all(window);
	gtk_widget_hide(statusbar);
	gtk_main();
	return 0;
}
