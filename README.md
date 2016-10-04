#####Salomon Smeke
##HW2

###Thought process:

When I began looking at my perfomance figures. The following was the state of my program:

https://github.com/SalomonSmeke/comp410hw2/commit/f6c44f4406dee999727223989013065e0a62fe82#diff-d759577e53e2ce061239002d8a592cc5

For context: There is a fairly complex buffer going on. I wanted it to write `\_o_/` over and over. So my buffer was initialized with a switch statement and all that jazz to get the desired effect.

When I saw my performance figures, I was confused:
`This all seems so linear! Double the buffer, half the time.`

In my eyes. This made no sense. Writing to a hard disk typically involves a block, and my SSD is AF 4K page, so I imagined that anything smaller than 4KB as a buffer would be problematic. I figured: Well, the hard drive will have to go back and fill in the previous sector, completely re-writing it.  It therefore stands to reason that there should be a giant jump in performance when we hit 4K and its multiples.

Nope. Linear.

Huh.

I reasoned, that mayhaps, the benefits of larger buffers were being diminished by the instantiation of my buffer.

I changed my code to just dump random uninitialized data.

Nothing. Still linear.

Alright. I suppose the hard drive format isnt a huge factor. At this point i wondered if maybe the writes dont flush until the file is closed. Mayhaps, that would mean that the entire contents are written at once. So the buffer doesnt play a part here.

Then it hit me.

For i in range -> write is called range times.
when range/2 time is roughly /2.

Could it really be this simple? The syscall soft interrupt is the deciding factor?

I cannot believe that flew past me. Especially given that we talked about this in class. Though, my idea was cool!

###Afterthoughts:

I dont know why i segfault at 10MB. I certainly have 10MB of ram available to build my buffer. I tried in mint and OSX (final perfomance numbers from OSX because I am home for the Jewish holiday and do not have my mint VM available to me).

Why is OSX performing so poorly? My VM managed 1.4 seconds on the smallest buffer... And the VM is hosted on OSX. HMMMMM. FISHY.

Go ahead and run test.sh if youd like to check it out for yourself!

Please note! I started this by working alongside Tyler Bobella. We did NOT copy each others code. We DID share online resources like: `https://filippo.io/linux-syscall-table/`. We mostly talked about what the assignment was about.
