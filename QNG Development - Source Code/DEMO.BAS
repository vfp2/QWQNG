5 PRINT
10 OPEN "QNG" FOR OUTPUT AS #1
20 PRINT #1, "M8088"                    'must use hard mode setting
30 CLOSE #1                             'because device is closed & reopened

110 OPEN "QNG" FOR INPUT AS #1          'open device for input
120 PRINT "Normal distribution"
130 FOR n = 1 TO 6                      'loop to get 6 values
140 INPUT #1, x                         'read normal precision float
150 PRINT n; x
160 NEXT n
170 CLOSE #1

210 OPEN "QNG" FOR OUTPUT AS #1
220 PRINT #1, "M800C"
230 CLOSE #1

310 OPEN "QNG" FOR INPUT AS #1
320 PRINT "Uniform distribution"
330 FOR n = 1 TO 6                      'loop to get 6 values
340 INPUT #1, xx#                       'read high precision float
350 PRINT n; xx#
360 NEXT n
370 CLOSE #1

410 OPEN "QNG" FOR OUTPUT AS #1
420 PRINT #1, "M8010"
430 CLOSE #1

510 OPEN "QNG" FOR INPUT AS #1
520 PRINT "Uniform binary integers"
530 FOR n = 1 TO 6                      'loop to get 6 values
540 INPUT #1, i%                        'read integer, 0..1
550 PRINT n; i%
560 NEXT n
570 CLOSE #1

999 END

