/*
 * Configuration/Store.h - ConfigurationStore class
 *
 * Copyright (c) 2009-2010 Tobias Doerffel <tobydox/at/users/dot/sf/dot/net>
 *
 * This file is part of iTALC - http://italc.sourceforge.net
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */

#ifndef _CONFIGURATION_STORE_H
#define _CONFIGURATION_STORE_H

#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QVariant>

namespace Configuration
{

class Object;

class Store
{
public:
	enum Backends
	{
		LocalBackend,	// registry or similiar
		XmlFile
	} ;
	typedef Backends Backend;

	enum Scopes
	{
		Personal,	// for current user
		Global,		// for all users
		System		// system-wide (service settings etc.)
	} ;
	typedef Scopes Scope;


	Store( Backend backend, Scope scope ) :
		m_backend( backend ),
		m_scope( scope )
	{
	}

	Backend backend() const
	{
		return m_backend;
	}

	Scope scope() const
	{
		return m_scope;
	}

	virtual void load( Object *obj ) = 0;
	virtual void flush( Object *obj ) = 0;


private:
	const Backend m_backend;
	const Scope m_scope;

} ;

}

#endif
