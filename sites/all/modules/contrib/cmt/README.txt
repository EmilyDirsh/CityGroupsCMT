
CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Installation
! * Case Tracker Caveats!
! * Case Tracker URLs
! * Mail Sending and Receiving
! * XML-RPC Connections
! * Case Tracker Terminology


INTRODUCTION
------------

Current Maintainer: Benjamin Melan�on 

Original Sponsor: Google Summer of Code
Original Developers: Agaric Design Collective
Oversight: Fago (http://drupal.org/user/16747)

Community Managed Taxonomy (or categories) allows any user with permissions to add terms, suggest placement, or recommend merging terms.

INSTALLATION
------------

1. Copy the files to your sites/SITENAME/modules directory.

2. Enable the Community managed taxonomy module at admin/modules.

!!!!!!!!

3. Assign the project and case node type and other relevant case options at
   admin/settings/casetracker. Case Tracker ships with simplistic "Project"
   and "Case" types in its casetracker_basic.module; although you can use
   these, you will get stronger flexibility by assigning it to a CCK or
   Flexinode content type of your own creation, or an Organic Group.

4. Customize case types, priorities, and states at admin/casetracker.

5. Enable permissions in admin/access.

Note: for more project.module-like functionality, try installing the
comment_upload.module and enabling comment attachments for case nodes.


CASE TRACKER CAVEATS!
---------------------

Some common gotchas which are, at the moment, "by design":

 * The "Last modified" value of Case Tracker cases is determined by the
   timestamp of the last comment attached to them (or, in the absence of
   a single comment, the node creation time). This requires that the
   comment.module (and node_comment_statistics table) are enabled and
   created. We CAN think of some use cases for not requiring comments on
   a case, but we think them edge cases and not enough to cater to. If
   you feel otherwise, don't hesitate to voice your opinion.

 * If you have node types with existing content (like already created
   Organic Groups), setting the Organic Group node type to be a Case
   Tracker project will NOT convert your existing content - the change
   will only apply to newly created Organic Groups. This may get fixed
   in the future: see http://drupal.org/node/65571 for the latest.


CASE TRACKER URLS
-----------------

The project based URLs we provide are briefly described below:

  /casetracker/projects
  /casetracker/projects/all
    Displays a list of all projects.

  /casetracker/projects/my
    Displays a list of projects created by the current user.

Case URL filtering is far more powerful, and supports a wide variety of
filters. "Unkeyed" filters are simply words or numbers that attempt to
satisfy the most common and relevant searches. For example, the word "my"
restricts the search to projects and cases the user has created, whereas
another unkeyed filter, "all", doesn't. Numbers like 13 or 15 usually refer
to a project or case ID: whatever makes the most sense at the time.

"Keyed" filters, however, have a name (the "key") and a value. To search
for cases that are of node type "casetracker_basic_case" only, you'd use a
keyed filter of "type:casetracker_basic_case". To show all cases that have
been created by users 23 and 35, you'd use "author:23,35", and so on.

The basic format of a Case Tracker case filter is:

  /casetracker/cases/PROJECT_FILTERS/CASE_FILTERS

The available project filters are described below:

    all   - show cases from all available projects.
    my    - show cases from projects the current user has created.
    ##    - show cases from only these project IDs.

The available case filters are described below:

  CASE UNKEYED FILTERS:
    all        - show all cases that match the project filters.
    my         - show current user's cases that match project filters.
    assigned   - show current user's assigned cases that match project filter.

  CASE KEYED FILTERS:
    assigned   - a comma separated list of uids that are assigned a case.
    author     - a comma separated list of uids that created a case.
    state      - a comma separated list of state IDs to filter by.
    type       - a comma separated list of node types to filter by.

Some EXAMPLES of these filters are below - these examples DO NOT
show every possible variation (as that would be rather timeconsuming):

  /casetracker/cases
  /casetracker/cases/all
  /casetracker/cases/all/all
    Display all cases for all projects.

  /casetracker/cases/my
  /casetracker/cases/my/all
    Display all cases in projects created by the current user.

  /casetracker/cases/all/my
    Display all cases created by the current user in all projects.

  /casetracker/cases/my/my
    Display all cases and projects created by the current user.

  /casetracker/cases/all/assigned
    Display all cases assigned to the current user in all projects.

  /casetracker/cases/14
  /casetracker/cases/14/all
    Display all cases assigned to project node ID 14.

  /casetracker/cases/all/state:1
    Display all cases with a state ID of 1.

  /casetracker/cases/my/state:4
    Display cases from my projects with a state ID of 4.

  /casetracker/cases/14/state:12
    Display cases from project node ID 14 with a state ID of 12.

But that's not all. To make things more deliciously confusing, you can
space-separate multiple filters and comma-separate values of a keyed
filter to get even more fine-turned searches:

  /casetracker/cases/all/assigned my
    Display cases from all projects which the current user
    has either opened, or which have been assigned to them.

  /casetracker/cases/my/my state:1
    Display cases in projects created by the current user that
    the current user has opened and which have a state ID of 1.

  /casetracker/cases/all/assigned my state:12,13
    Display cases in all projects that have been opened by the
    current user or have been assigned to the current user, and
    which have state IDs 12 or 13.


MAIL SENDING AND RECEIVING
--------------------------

Case Tracker, and specifically casetracker_mail.module, has the ability to
send out custom emails whenever an issue is created or a comment posted, as
well as receive messages and post them as new cases or comments. In practice,
this works great for simple node types, but breaks down under advanced configs
with CCK and Flexinode (specifically, emails are sent and received, but you
are unable to use any of your created fields as values). Additional funding
and development are required to hammer those issues out.

Creating cases or leaving comments through email requires the Mailhandler
module to be installed and configured properly. A new case can be created
with the following sample email sent to your Mailhandler mailbox:

 project_number: 500
 type: casetracker_basic_case
 case_title: This is a case title!
 assign_to: Morbus Iff
 case_status: open
 case_priority: 1-high
 case_type: bug

 This is the case body.

Emailed comments have no special characteristics, save that they must be
in reply to the original sent Case Tracker case email (the message IDs are
calculated and stored as a reference).


XML-RPC CONNECTIONS
-------------------

Very rudimentary support for creation of Case Tracker cases via XML-RPC is
available. This has not been tested much, and it is certainly not a fully
featured XML-RPC server (you can only create new cases, not retrieve or
edit existing cases, etc.). If you'd like to fund future development on the
XML-RPC capabilities of Case Tracker, don't hesitate to contact one of the
developers listed in at the beginning of this README.txt.

For an example of the XML-RPC capabilities:

1. Enable the casetracker_xmlrpc.module as you would any other.

2. Give the "create cases via XML-RPC" permission to a user role.

3. Modify the xmlrpc_example.php included in the Case Tracker distribution
   with the correct connection information, then run it from the command
   line or via your browser. This example requires the "XML-RPC for PHP"
   open source library from http://sourceforge.net/projects/phpxmlrpc/.

The example defaults to creating a node of type "casetracker_basic_case",
which is only available from the casetracker_basic.module. We assume that
those who are interested in XML-RPC capabilities are planning to write their
own client, and probably have enough know-how to "make things work" (such
as modifying the client to create node types of CCK or Flexinode variety).


CASE TRACKER TERMINOLOGY
------------------------

Case Tracker assigns every project a unique project number that starts at 100
and increments by another hundred for each new project (200, 300, 400, etc.).
Similarly, cases receive individual case numbers that are unique to the
project and start at 1, incrementing by 1 for each new case (2, 3, 4, etc.)
within the project. Together, these two numbers combine to create a unique
case number in the Case Tracker system, such as 300-4 (project number 300,
case number 4). These numbers have no correlation to the Drupal node system.

We have attempted to standardize on the following terminology:

 * project ID: the node ID of the project.
 * project number: 100, 200, 300, as above.
 * case ID: the node ID of the case.
 * case number (individual): 1, 2, 3, etc. as above.
 * case number (combined): 100-1, 200-43, etc. as above.
 