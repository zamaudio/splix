/*
 * 	    request.h                 (C) 2006-2008, Aurélien Croc (AP²C)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; version 2 of the License.
 * 
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the
 *  Free Software Foundation, Inc.,
 *  59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 *  $Id$
 * 
 */
#ifndef _REQUEST_H_
#define _REQUEST_H_

#include "printer.h"

class PPDFile;

/**
  * @brief This class contains all the information about the requested job.
  *
  * During the job information loading, this class will instantiate @ref Printer
  * and initialize it to have information on the printer which will be used to
  * print the job.
  * This instance is mainly used by the QPDL render.
  */
class Request 
{
    public:
        enum Duplex {
            None,
            LongEdge,
            ShortEdge,
            Manual,
        };

    protected:
        PPDFile*                _ppd;

        const char*             _username;
        const char*             _jobname;
        const char*             _jobtitle;
        unsigned long           _copiesNr;

        Printer                 _printer;

        Duplex                  _duplex;

    public:
        /**
          * Initialize the instance.
          */
        Request();
        /**
          * Destroy the instance.
          */
        virtual ~Request();

    public:
        /**
          * Load a new request.
          * @param ppd the PPDfile instance
          * @param jobname the job ID
          * @param username the name of the user which make this job
          * @param jobtitle the job title
          * @param copiesNr the number of copies to print
          * @return TRUE if the request has been successfully loaded. Otherwise
          *         it returns FALSE.
          */
        bool                    loadRequest(PPDFile* ppd, 
                                    const char *jobname, const char *username, 
                                    const char *jobtitle, 
                                    unsigned long copiesNr);

    public:
        /**
          * @return the PPDFile instance.
          */
        PPDFile*                ppd() const {return _ppd;}
        /**
          * @return the printer instance.
          */
        const Printer*          printer() const {return &_printer;}

};

#endif /* _REQUEST_H_ */

/* vim: set expandtab tabstop=4 shiftwidth=4 smarttab tw=80 cin enc=utf8: */

