
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* "%code requires" blocks.  */

/* Line 1676 of yacc.c  */
#line 40 "stack_description_parser.y"

    #include "types.h"

    #include "material.h"
    #include "die.h"
    #include "stack_element.h"
    #include "inspection_point.h"
    #include "analysis.h"
    #include "output.h"
    #include "stack_description.h"



/* Line 1676 of yacc.c  */
#line 54 "stack_description_parser.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _2RM = 258,
     _4RM = 259,
     AMBIENT = 260,
     AREA = 261,
     AVERAGE = 262,
     BOTTOM = 263,
     CAPACITY = 264,
     CELL = 265,
     CHANNEL = 266,
     CHIP = 267,
     COEFFICIENT = 268,
     CONDUCTIVITY = 269,
     CONNECTION = 270,
     COOLANT = 271,
     DARCY = 272,
     DIAMETER = 273,
     DIE = 274,
     DIMENSIONS = 275,
     DISTRIBUTION = 276,
     FINAL = 277,
     FIRST = 278,
     FLOORPLAN = 279,
     FLOW = 280,
     HEAT = 281,
     HEIGHT = 282,
     INCOMING = 283,
     INITIAL_ = 284,
     INLINE = 285,
     LAST = 286,
     LAYER = 287,
     LENGTH = 288,
     MATERIAL = 289,
     MAXIMUM = 290,
     MICROCHANNEL = 291,
     MINIMUM = 292,
     OUTPUT = 293,
     PIN = 294,
     PINFIN = 295,
     PITCH = 296,
     PMAP = 297,
     RATE = 298,
     SIDE = 299,
     SINK = 300,
     SLOT = 301,
     SOLVER = 302,
     SOURCE = 303,
     SPREADER = 304,
     STACK = 305,
     STAGGERED = 306,
     STATE = 307,
     STEADY = 308,
     STEP = 309,
     TCELL = 310,
     TCOOLANT = 311,
     TEMPERATURE = 312,
     TFLP = 313,
     TFLPEL = 314,
     THERMAL = 315,
     TMAP = 316,
     TO = 317,
     TOP = 318,
     TRANSFER = 319,
     TRANSIENT = 320,
     VELOCITY = 321,
     VOLUMETRIC = 322,
     WALL = 323,
     WIDTH = 324,
     DVALUE = 325,
     IDENTIFIER = 326,
     PATH = 327
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 55 "stack_description_parser.y"

    double                double_v ;
    String_t              string ;
    Material_t           *material_p ;
    Coolant_t             coolant_v ;
    ChannelModel_t        channel_model_v ;
    Die_t                *die_p ;
    Layer_t              *layer_p ;
    StackElement_t       *stack_element_p ;
    InspectionPoint_t    *inspection_point_p ;
    OutputInstant_t       output_instant_v ;
    OutputQuantity_t      output_quantity_v ;



/* Line 1676 of yacc.c  */
#line 159 "stack_description_parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif




