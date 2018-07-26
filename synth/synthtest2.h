#ifndef SYNTHTEST_H
#define SYNTHTEST_H
#include "Synth.h"
#include "ModuleConstant.h"
#include "ModuleWavetableOsc.h"
#include "ModuleLowpassFilter.h"
#include "ModuleLFO.h"

class SynthTest : public Synth
{
public:
    ModuleConstant param[8];

    SynthTest()
    {

        /*

        This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCB4eDNpIGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIHh4M2kKcGF0Y2gvYWRkLW5vZGUgc2FkNCB4b2E2
        IGVzcG5vZGUvY29tbWVudCBDb21tZW50Cm5vZGUvdHVybi1vbiB4b2E2Cm5vZGUvYWRkLWlubGV0IHhvYTYgenozZiBlc3Bub2RlL3N0cmluZyBjb21tZW50IGNvbW1lbnQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBsaDZnIGVzcG5vZGUvbG93cGFzcyBMb3clMjBQYXNz
        JTIwRmlsdGVyCm5vZGUvdHVybi1vbiBsaDZnCm5vZGUvYWRkLWlubGV0IGxoNmcgZXBrcyBlc3Bub2RlL3N0cmluZyBhdWRpb19pbnB1dCBhdWRpb19pbnB1dApub2RlL2FkZC1pbmxldCBsaDZnIGFkcXogZXNwbm9kZS9zdHJpbmcgY3V0b2ZmX2lucHV0IGN1dG9m
        Zl9pbnB1dApub2RlL2FkZC1pbmxldCBsaDZnIHFnYWsgZXNwbm9kZS9zdHJpbmcgcmVzb25hbmNlX2lucHV0IHJlc29uYW5jZV9pbnB1dApub2RlL2FkZC1vdXRsZXQgbGg2ZyBrczQ1IGVzcG5vZGUvc3RyaW5nIE91dCBPdXQKcGF0Y2gvYWRkLW5vZGUgc2FkNCB6
        YXF3IGVzcG5vZGUvc2FtcGxlcGFjayBTYW1wbGUlMjBQYWNrJTIwRWRpdG9yCm5vZGUvdHVybi1vbiB6YXF3Cm5vZGUvYWRkLWlubGV0IHphcXcgZTh6aiBlc3Bub2RlL3N0cmluZyBjb21tZW50IGNvbW1lbnQKbm9kZS9hZGQtaW5sZXQgemFxdyBmam41IGVzcG5v
        ZGUvc3RyaW5nIHNhbXBsZV9uYW1lIHNhbXBsZV9uYW1lCnBhdGNoL2FkZC1ub2RlIHNhZDQgOTNqNyBlc3Bub2RlL2RhYyBBdWRpbyUyMERBQwpub2RlL3R1cm4tb24gOTNqNwpub2RlL2FkZC1pbmxldCA5M2o3IHh5cW0gZXNwbm9kZS9zdHJpbmcgYXVkaW9faW5w
        dXQgYXVkaW9faW5wdXQKcGF0Y2gvYWRkLW5vZGUgc2FkNCA4NjBnIGVzcG5vZGUvb3NjaWxsYXRvciBPc2NpbGxhdG9yCm5vZGUvdHVybi1vbiA4NjBnCm5vZGUvYWRkLWlubGV0IDg2MGcgajA3cCBlc3Bub2RlL3N0cmluZyBmcmVxdWVuY3lfaW5wdXQgZnJlcXVl
        bmN5X2lucHV0Cm5vZGUvYWRkLWlubGV0IDg2MGcgaTI0aCBlc3Bub2RlL3N0cmluZyB3YXZldGFibGVfaW5wdXQgd2F2ZXRhYmxlX2lucHV0Cm5vZGUvYWRkLW91dGxldCA4NjBnIGEwc2sgZXNwbm9kZS9zdHJpbmcgT3V0IE91dApwYXRjaC9hZGQtbm9kZSBzYWQ0
        IG1lNG0gZXNwbm9kZS9jb25zdGFudCBDb25zdGFudApub2RlL3R1cm4tb24gbWU0bQpub2RlL2FkZC1pbmxldCBtZTRtIGl3aXQgZXNwbm9kZS9zdHJpbmcgdXNlci12YWx1ZSB1c2VyLXZhbHVlCm5vZGUvYWRkLW91dGxldCBtZTRtIDdhZzUgZXNwbm9kZS9zdHJp
        bmcgbnVtYmVyIG51bWJlcgpwYXRjaC9hZGQtbm9kZSBzYWQ0IHRzd2QgZXNwbm9kZS9jb25zdGFudCBDb25zdGFudApub2RlL3R1cm4tb24gdHN3ZApub2RlL2FkZC1pbmxldCB0c3dkIG1heXYgZXNwbm9kZS9zdHJpbmcgdXNlci12YWx1ZSB1c2VyLXZhbHVlCm5v
        ZGUvYWRkLW91dGxldCB0c3dkIG4wMnkgZXNwbm9kZS9zdHJpbmcgbnVtYmVyIG51bWJlcgpub2RlL21vdmUgeHgzaSAzMCAyMApub2RlL21vdmUgeG9hNiA5NzcgNzYKbm9kZS9tb3ZlIGxoNmcgODEyIDMxNgpub2RlL21vdmUgemFxdyA1MDcgMjQ2Cm5vZGUvbW92
        ZSA5M2o3IDEzMjkgMzIwCm5vZGUvbW92ZSA4NjBnIDUxMyA0MDQKbm9kZS9tb3ZlIG1lNG0gMzIxIDM3NApub2RlL21vdmUgdHN3ZCAzMjQgNDg3Cm91dGxldC9jb25uZWN0IGtzNDUgeHlxbSBucjVsCm91dGxldC9jb25uZWN0IGEwc2sgZXBrcyA3aWVmCm91dGxl
        dC9jb25uZWN0IDdhZzUgajA3cCBxdXU4Cm91dGxldC9jb25uZWN0IG4wMnkgaTI0aCB0cHpxCm5vZGUvdXBkYXRlLWlubGV0IHhvYTYgenozZiBjb21tZW50IHR5cGUlMjBjb21tZW50JTIwaGVyZS4uCm5vZGUvdXBkYXRlLWlubGV0IGxoNmcgYWRxeiBjdXRvZmZf
        aW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBsaDZnIHFnYWsgcmVzb25hbmNlX2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgemFxdyBmam41IHNhbXBsZV9uYW1lIFNhbXBsZTEKbm9kZS91cGRhdGUtaW5sZXQgOTNqNyB4eXFtIGF1ZGlvX2lucHV0IDAKbm9kZS91
        cGRhdGUtaW5sZXQgODYwZyBqMDdwIGZyZXF1ZW5jeV9pbnB1dCA0NDAKbm9kZS91cGRhdGUtaW5sZXQgODYwZyBpMjRoIHdhdmV0YWJsZV9pbnB1dCAzCm5vZGUvdXBkYXRlLW91dGxldCBtZTRtIDdhZzUgbnVtYmVyIDQ0MApub2RlL3VwZGF0ZS1pbmxldCBtZTRt
        IGl3aXQgdXNlci12YWx1ZSA0NDAKbm9kZS91cGRhdGUtb3V0bGV0IHRzd2QgbjAyeSBudW1iZXIgMwpub2RlL3VwZGF0ZS1pbmxldCB0c3dkIG1heXYgdXNlci12YWx1ZSAz
        --ENDESPNODEPATCH--

        */



        ModuleLowpassFilter *moduleLowpassFilter_1 = new ModuleLowpassFilter();
        ModuleWavetableOsc *moduleWavetableOsc_1 = new ModuleWavetableOsc();


        moduleWavetableOsc_1->frequency_input = new ModuleConstant(440);
        moduleWavetableOsc_1->wavetable_input = new ModuleConstant(3);
        moduleLowpassFilter_1->audio_input=moduleWavetableOsc_1;


        this->last_module = moduleLowpassFilter_1;


        // end of espnode86 generated code //


  }
};
#endif // SYNTHTEST_H
