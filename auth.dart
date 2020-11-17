import 'package:asha_patient_app_flutter/providers/userProvider.dart';
import 'package:asha_patient_app_flutter/widgets/customAppBar.dart';
import 'package:asha_patient_app_flutter/widgets/drawer.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter/material.dart';
import 'package:flutter_svg/svg.dart';
import 'package:intl/intl.dart';
import 'package:provider/provider.dart';

class InvoicesScreen extends StatelessWidget {
  BuildContext _context;
  @override
  Widget build(BuildContext context) {
    final patientId = Provider.of<UserData>(context, listen: false).userId;
    return Scaffold(
      backgroundColor: Colors.white,
      appBar: customAppBar(() => Scaffold.of(_context).openDrawer(), context,
          showBell: true, title: 'INVOICES'),
      drawer: SideDrawer(),
      body: SingleChildScrollView(
        child: Padding(
          padding: const EdgeInsets.only(top: 10.0),
          child: Column(
            children: <Widget>[
              StreamBuilder<QuerySnapshot>(
                  stream: Firestore.instance
                      .collection('appointments')
                      .where('patientId', isEqualTo: patientId)
                      //    .orderBy('appointmentDate', descending: true)
                      .snapshots(),
                  builder: (context, snapshot) {
                    _context = context;
                    if (!snapshot.hasData) {
                      return Container(
                        height: MediaQuery.of(context).size.height * 0.6,
                        child: Center(
                          child: Padding(
                            padding: const EdgeInsets.all(30),
                            child: CircularProgressIndicator(
                              backgroundColor: Colors.lightBlueAccent,
                            ),
                          ),
                        ),
                      );
                    }
                    final docs = snapshot.data.documents;
                    int cnt = 0;
                    print("fo...............................................");
                    print(docs.length);
                    List<Map<String, dynamic>> cc = [];
                    for (var doc in docs) {
                      int mode = -1;
                      if (doc['appointmentMode'][0] != -1)
                        mode = 0;
                      else if (doc['appointmentMode'][1] != -1)
                        mode = 1;
                      else if (doc['appointmentMode'][2] != -1)
                        mode = 2;
                      else if (doc['appointmentMode'][3] != -1) mode = 3;
                      int price = doc['appointmentMode'][0] +
                          doc['appointmentMode'][1] +
                          doc['appointmentMode'][2] +
                          doc['appointmentMode'][3] +
                          3;
                      cc.add({
                        "name": doc['psychologistName'],
                        "startTime": doc['appointmentSlot'],
                        "endTime": doc['appointmentSlotEnd'],
                        "price": price,
                        "paymentDate": doc['appointmentDate'],
                        "status": doc['status'],
                        "mode": mode
                      });
                    }
                    print(cc.length);

                    return cc.length != 0
                        ? Center(
                            child: Padding(
                              padding: const EdgeInsets.all(30),
                              child: Text(
                                "You have not completed any appointments yet.",
                                textAlign: TextAlign.center,
                                style: TextStyle(
                                  fontFamily: 'SourceSansPro',
                                  fontSize: 16,
                                ),
                              ),
                            ),
                          )
                        : ListView.builder(
                            shrinkWrap: true,
                            itemBuilder: (BuildContext cxt, int index) {
                              return InvoiceTile(
                                  cc[index]['name'],
                                  cc[index]['startTime'],
                                  cc[index]['endTime'],
                                  cc[index]['paymentDate'],
                                  cc[index]['status'],
                                  cc[index]['mode'],
                                  cc[index]['price']);
                            },
                            itemCount: cc.length,
                          );
                  }),
            ],
          ),
        ),
      ),
    );
  }
}

class InvoiceTile extends StatelessWidget {
  String name, status;
  int startTime, endTime, mode, price;
  Timestamp paymentDate;
  InvoiceTile(this.name, this.startTime, this.endTime, this.paymentDate,
      this.status, this.mode, this.price);

  modeIcon(int mode) {
    if (mode == 0) return Icons.videocam;
    if (mode == 1) return Icons.person;
    if (mode == 2) return Icons.chat;
    if (mode == 3) return Icons.call;
  }

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.symmetric(horizontal: 10),
      child: Card(
        child: Padding(
          padding: const EdgeInsets.symmetric(
            horizontal: 10,
            vertical: 20,
          ),
          child: Row(
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: <Widget>[
              Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                mainAxisAlignment: MainAxisAlignment.start,
                children: <Widget>[
                  Text(
                    name,
                    style: TextStyle(
                        fontWeight: FontWeight.bold,
                        fontFamily: 'SourceSansPro',
                        fontSize: 16),
                  ),
                  Text(
                    DateFormat.jm().format(
                            Timestamp.fromMillisecondsSinceEpoch(startTime)
                                .toDate()) +
                        "-" +
                        DateFormat.jm().format(
                            Timestamp.fromMillisecondsSinceEpoch(endTime)
                                .toDate()) +
                        ', ' +
                        DateFormat.MMMd().format(
                            Timestamp.fromMillisecondsSinceEpoch(startTime)
                                .toDate()),
                    style: TextStyle(
                      fontSize: 14,
                      fontFamily: 'SourceSansPro',
                    ),
                  ),
                  Text(
                    'Booking Date - ' +
                        DateFormat.MMMEd().format(paymentDate.toDate()),
                    style: TextStyle(
                      fontSize: 14,
                      fontFamily: 'SourceSansPro',
                    ),
                  ),
                ],
              ),
              Column(
                crossAxisAlignment: CrossAxisAlignment.end,
                mainAxisAlignment: MainAxisAlignment.start,
                children: <Widget>[
                  Padding(
                    padding: const EdgeInsets.all(0.0),
                    child: Row(
                      children: <Widget>[
                        Icon(modeIcon(mode),
                            size: 20, color: Theme.of(context).accentColor),
                        SizedBox(
                          width: 10,
                        ),
                        Text(
                          status.toUpperCase(),
                          style: TextStyle(
                            fontSize: 14,
                            color: Theme.of(context).accentColor,
                            fontWeight: FontWeight.w400,
                            fontFamily: 'SourceSansPro',
                          ),
                        ),
                      ],
                    ),
                  ),
                  Padding(
                    padding: const EdgeInsets.all(0.0),
                    child: Text(
                      "Rs. " + price.toString(),
                      style: TextStyle(
                        fontSize: 14,
                        color: Theme.of(context).accentColor,
                        fontWeight: FontWeight.w400,
                        fontFamily: 'SourceSansPro',
                      ),
                    ),
                  )
                ],
              )
            ],
          ),
        ),
      ),
    );
  }
}
