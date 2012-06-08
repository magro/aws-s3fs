/**
 * \file aws-s3fs.h
 * \brief Definitions shared among the aws-s3fs source code files.
 *
 * Copyright (C) 2012 Ole Wolf <wolf@blazingangles.com>
 *
 * This file is part of aws-s3fs.
 * 
 * aws-s3fs is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <config.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <syslog.h>


#define bool_equal( a, b ) ( (a) ? (b) : !(b) )

/** Path of the configuration file. */
#include "sysconffile.h"

/** Default configuration values. */
#define DEFAULT_REGION     "US Standard"
#define DEFAULT_BUCKETNAME "bucket"
#define DEFAULT_PATH       "/"
#define DEFAULT_KEY_ID     "accesskeyid"
#define DEFAULT_SECRET_KEY "secretkey"
#define DEFAULT_LOG_FILE   "/var/log/aws-s3fs.log"
#define DEFAULT_VERBOSE    false


enum bucketRegions {
    US_STANDARD, OREGON, NORTHERN_CALIFORNIA, IRELAND,
    SINGAPORE, TOKYO, SAO_PAULO
};


struct configurationBoolean {
    bool value;
    bool isset;
};

struct configuration {
    enum bucketRegions          region;
    /*@null@*/ char             *bucketName;
    /*@null@*/ char             *path;
    /*@null@*/ char             *keyId;
    /*@null@*/ char             *secretKey;
    /*@null@*/ char             *logfile;
    struct configurationBoolean verbose;
};

struct cmdlineConfiguration {
    struct configuration configuration;
    /*@null@*/ char      *configFile;
    bool                 regionSpecified;
    bool                 bucketNameSpecified;
    bool                 pathSpecified;
    bool                 keyIdSpecified;
    bool                 secretKeySpecified;
    bool                 logfileSpecified;
};


/* In logger.c */
void Syslog( int priority, const char *format, ... );
const char *LogFilename( void );
void EnableLogging( void );
void DisableLogging( void );
void InitLog( const char *logfile );
void CloseLog( void );


/* In common.c */
void VerboseOutput( const char *format, ... );

/* In aws-s3fs.c. */
void
Configure(
    struct configuration *configuration,
    char                 **mountPoint,
    int                  argc,
    const char * const   *argv
);

extern bool verboseOutput;
/*@-exportlocal@*/
extern struct configuration configuration;
/*@+exportlocal@*/



/* In config.c. */
void CopyDefaultString(
    char       **key,
    const char *value
);

bool
ReadConfigFile(
    const FILE           *fp,
    const char           *configFilename,
    struct configuration *configuration
);

void
ConfigSetKey(
    char       **keyId,
    char       **secretKey,
    const char *configValue,
    bool       *configError
);

void
ConfigSetRegion(
    enum bucketRegions *region,
    const char         *configName,
    bool               *configError
);

void
ConfigSetPath(
    char       **path,
    const char *configPath
);


/* In common.c. */

/*@null@*/ /*@dependent@*/ const FILE*
TestFileReadable(
    const char *filename
);


/* In decodecmdline.c. */
bool
DecodeCommandLine(
    struct cmdlineConfiguration *cmdlineConfiguration,
    /*@out@*/ char              **mountPoint,
    int                         argc,
    const char * const          *argv
);

