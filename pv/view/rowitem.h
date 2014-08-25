/*
 * This file is part of the PulseView project.
 *
 * Copyright (C) 2013 Joel Holdsworth <joel@airwebreathe.org.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#ifndef PULSEVIEW_PV_VIEW_HEADERITEM_H
#define PULSEVIEW_PV_VIEW_HEADERITEM_H

#include "selectableitem.h"

namespace pv {
namespace view {

class View;

class RowItem : public SelectableItem
{
public:
	/**
	 * Constructor.
	 */
	RowItem();

	/**
	 * Returns true if the item is visible and enabled.
	 */
	virtual bool enabled() const = 0;

	/**
	 * Gets the vertical layout offset of this signal.
	 */
	int v_offset() const;

	/**
	 * Sets the vertical layout offset of this signal.
	 */
	void set_v_offset(int v_offset);

	/**
	 * Sets the view that owns this trace in the view trace hierachy.
	 * @param The new owner of the trace.
	 */
	void set_view(pv::view::View *view);

	/**
	 * Gets the y-offset of the axis.
	 */
	int get_y() const;

	/**
	 * Paints the background layer of the trace with a QPainter
	 * @param p the QPainter to paint into.
	 * @param left the x-coordinate of the left edge of the signal
	 * @param right the x-coordinate of the right edge of the signal
	 **/
	virtual void paint_back(QPainter &p, int left, int right);

	/**
	 * Paints the mid-layer of the trace with a QPainter
	 * @param p the QPainter to paint into.
	 * @param left the x-coordinate of the left edge of the signal
	 * @param right the x-coordinate of the right edge of the signal
	 **/
	virtual void paint_mid(QPainter &p, int left, int right);

	/**
	 * Paints the foreground layer of the trace with a QPainter
	 * @param p the QPainter to paint into.
	 * @param left the x-coordinate of the left edge of the signal
	 * @param right the x-coordinate of the right edge of the signal
	 **/
	virtual void paint_fore(QPainter &p, int left, int right);

	/**
	 * Paints the signal label.
	 * @param p the QPainter to paint into.
	 * @param right the x-coordinate of the right edge of the header
	 * 	area.
	 * @param hover true if the label is being hovered over by the mouse.
	 */
	virtual void paint_label(QPainter &p, int right, bool hover) = 0;

	/**
	 * Computes the outline rectangle of a label.
	 * @param right the x-coordinate of the right edge of the header
	 * 	area.
	 * @return Returns the rectangle of the signal label.
	 */
	virtual QRectF label_rect(int right) = 0;

public:
	virtual void hover_point_changed();

protected:
	pv::view::View *_view;

	int _v_offset;
};

} // namespace view
} // namespace pv

#endif // PULSEVIEW_PV_VIEW_HEADERITEM_H
