# Overview

**Today, I will introduce you about how to install VMware Workstation and configure CentOS 8 on it.**

---

## I. Install VMware Workstation

1. Install VMware:
   - [VMWare Workstation 16 Pro](https://www.vmware.com/asean/products/workstation-pro/workstation-pro-evaluation.html)
2. Configure VMware:

   2.1: Click to run file installed

   2.2: Click next

   ![Screenshot1](images/Vmware-configuration-step1.png)

   2.3: Click I accept the terms in the License Agreement and click next

   ![Screenshot2](images/Vmware-configuration-step2.png)

   2.4: Click Enhanced keyboard Driver to use Keyboard in VM and click next

   ![Screenshot3](images/Vmware-configuration-step3.png)

   2.5: Click uncheck these checkbox and click next

   ![Screenshot4](images/Vmware-configuration-step4.png)

   2.6: Click next (By default these checkbox are chosen, if not you should click on)

   ![Screenshot5](images/Vmware-configuration-step5.png)

   2.7: Click Install

   ![Screenshot6](images/Vmware-configuration-step6.png)

   2.8: Click License

   ![Screenshot7](images/Vmware-configuration-step7.png)

   2.9: Enter License Key and Click Enter

   ![Screenshot8](images/Vmware-configuration-step8.png)

   There are so many ways to get License Key
   This link below I recommend to get Key:
   [License-Key-Vmware-Workstation-16-Pro](https://tinhte.vn/thread/download-vmware-workstation-pro-16-full-key-phan-mem-tao-may-ao.3217920/)

   2.10: Click Finish

   ![Screenshot9](images/Vmware-configuration-step9.png)

   (Additional Step)

   ![Screenshot10](images/WatchOut.png)

   If you have it, it's unnecessary for you guys to click YES, instead, you can **choose NO**.

   2.11: This is Graphic User Interface that you have after finishing installation

   ![Screenshot11](images/GUI.png)

---

## II. Install CentOS 8 on VMware Workstation 16

1.  At the top right corner you will see Toolbal

    ![Screenshot12](images/GUI.png)

2.  Click File to open this window and click New Virtual Machine

    ![Screenshot13](images/CentOs-step1.png)

3.  Choose Typical (recommended) and click next

    ![Screenshot14](images/CentOs-step2.png)

4.  Choose I will install the operating system later.

    ![Screenshot15](images/CentOs-step3.png)

    > In this step you should install in homepage of this OS, you can use link below to install CentOs 8

    [CentOS-8](http://isoredirect.centos.org/centos/8-stream/isos/x86_64/)

    As you can see, there are many links we can choose, click any links you like

    ![Screenshot16](images/CentOs-step4.png)

    After that, I recommend you guys to choose link that >= 4GB, because it will have Graphic User Interface which can be use easily

    ![Screenshot17](images/CentOs-step5.png)

5.  Choose Linux Operating System and Find Version CentOS-8

    ![Screenshot18](images/CentOs-step6.png)

6.  Create VM name & Location for your VM

    ![Screenshot19](images/CentOs-step7.png)

7.  Limit disk size and choose Split virtual disk for good UX

    > I think 20.0GB is enough, so you can use default

    ![Screenshot20](images/CentOs-step8.png)

8.  Click Customize Hardware

    ![Screenshot21](images/CentOs-step9.png)

9.  Choose Memory, Processors and Locate file ISO for VM

    > In this case, I choose 4GB for increasing UX. Because I have 8GB RAM. However, **2GB is enough**. So you can choose 2GB

    ![Screenshot22](images/CentOs-step10.png)

    > In this case, I also choose 2 processors & 2 cores per processor. But **Both of them 1 is enough**

    ![Screenshot23](images/CentOs-step11.png)

    > Locate your ISO file which you download in the step 4.

    ![Screenshot24](images/CentOs-step12.png)

    > > Close window

10. Click finish to complete configure

    ![Screenshot25](images/CentOs-step13.png)

11. Click Power on to run VM

    ![Screenshot26](images/CentOs-step14.png)

12. Wait for automatic boot finish

    ![Screenshot27](images/CentOs-step15.png)

13. Choose Install CentOs Linux 8

    ![Screenshot28](images/CentOs-step16.png)

14. Wait for loading

    ![Screenshot29](images/CentOs-step17.png)

15. Choose Language

    ![Screenshot30](images/CentOs-newStep15.png)

16. Configure Root Password

    ![Screenshot31](images/CentOs-newStep17.png)

17. Create your password

    ![Screenshot32](images/CentOs-newStep21.png)

    > When you finish, click **DONE** at the top right corner

18. Configure Installation Destination

    ![Screenshot33](images/CentOs-newStep18.png)

    > By default, The destination is appropriate, so you just click **DONE** to finish this step.

    ![Screenshot34](images/CentOs-newStep22.png)

19. Configure Network

    ![Screenshot35](images/CentOs-newStep19.png)

    > Click button here to turn on internet connection, and click **DONE** to finish this step.

    ![Screenshot36](images/CentOs-newStep20.png)

(Additional Step)

> For those who **don't want to use GUI** or **don't have enough GB in Disk** you can choose to use this OS without having GUI.

![Screenshot37](images/Additional%20Step.png)

> Click Software Selection

![Screenshot38](images/Additional%20Step2.png)

> Choose **Minimal Install** and click **DONE**

20. Click reboot to start again

![Screenshot30](images/CentOs-step18.png)

21. Wait for loading

    ![Sreenshot31](images/CentOs-step19.png)

22. Choose CentOS Stream

    ![Screenshot32](images/CentOs-step20.png)

23. Click License Information to accept

    ![Screenshot32](images/CentOs-newStep24.png)

24. Click I accept & Click Done

    ![Screenshot33](images/CentOs-step22.png)

25. Click Finish Configuration

    ![Screenshot34](images/CentOs-step23.png)

26. Click Next

    ![Screenshot35](images/CentOs-newStep25.png)

27. Click **off location services** and click **next**

    ![Screenshot36](images/CentOs-newStep26.png)

28. Click **Skip** in this step

    ![Screenshot37](images/CentOs-newStep27.png)

29. Create your username

    ![Screenshot38](images/CentOs-newStep28.png)

30. Create your password

    ![Screenshot39](images/CentOs-newStep29.png)

31. Start Using CentOs Stream

    ![Screenshot40](images/CentOs-newStep30.png)

32. **We're in**

    ![SCreenshot41](images/CentOs-lastStep.png)
