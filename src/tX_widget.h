/*
    terminatorX - realtime audio scratching software
    Copyright (C) 1999-2014  Alexander König
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
 
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
 
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
    File: tX_widget.h
 
    Description: Header to tX_widget.c
*/    


#ifndef __GTK_TX_H__
#define __GTK_TX_H__
#include <gdk/gdk.h>
#include <gtk/gtkwidget.h>

#include "tX_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#define GTK_TX(obj)          G_TYPE_CHECK_INSTANCE_CAST (obj, gtk_tx_get_type (), GtkTx)
#define GTK_TX_CLASS(klass)  GTK_CHECK_CLASS_CAST (klass, gtk_tx_get_type (), GtkTxClass)
#define GTK_IS_TX(obj)       G_TYPE_CHECK_INSTANCE_TYPE (obj, gtk_tx_get_type ())

typedef struct _GtkTx        GtkTx;
typedef struct _GtkTxClass   GtkTxClass;

typedef enum tx_widget_motion {
	NO_MOTION,
	MOTION_LEFT,
	MOTION_RIGHT
} tx_widget_motion;

struct _GtkTx {
	GtkWidget widget;

	int16_t *disp_data;
	int16_t *data;
	int samples;
	
	GdkColor colors[6];
	
	GdkColor *current_fg;
	GdkColor *current_bg;
	
	GdkColor *audio_colors_focus;
	GdkColor *audio_colors_nofocus;
	
	int spp;
	int yc;
	
	int lastmute;
	int do_showframe;
	
	GtkWidget *peer_scale;
	
	f_prec zoom;
		
	int cursor_pos;
	int cursor_x_pos;

	int display_width;
	int display_x_offset;
	
	int colors_allocated;

#ifdef USE_DISPLAY_NORMALIZE
	f_prec max_value;
#endif	

	cairo_surface_t* surface;
};

struct _GtkTxClass {
	GtkWidgetClass parent_class;
};

GtkWidget* gtk_tx_new	(int16_t *wavdata, int wavsamples);
GType gtk_tx_get_type	(void);
void gtk_tx_set_data  (GtkTx *tx, int16_t *wavdata, int wavsamples);
void gtk_tx_cleanup_pos_display (GtkTx *tx);
void	gtk_tx_update_pos_display  (GtkTx *tx, int sample, int mute);
void gtk_tx_show_frame(GtkTx *tx, int show);
void gtk_tx_set_zoom(GtkTx *tx, f_prec zoom);
void gtk_tx_update_colors(GtkTx *tx);
f_prec gtk_tx_get_zoom(GtkTx *tx);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif

