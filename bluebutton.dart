import 'package:flutter/material.dart';

class BlueButton extends StatelessWidget {
  final String text;
  final Function onPress;

  BlueButton(this.text, this.onPress);

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: onPress,
      child: Container(
        alignment: Alignment.center,
        height: 35.0,
        width: MediaQuery.of(context).size.width * 0.35,
        decoration: BoxDecoration(
          borderRadius: BorderRadius.circular(2.0),
          color: const Color(0xff072ac8),
          border: Border.all(width: 1.0, color: const Color(0xff072ac8)),
          boxShadow: [
            BoxShadow(
              color: const Color(0x29000000),
              offset: Offset(0, 3),
              blurRadius: 6,
            )
          ],
        ),
        child: Text(
          text,
          style: TextStyle(
            fontFamily: 'SourceSansPro',
            fontSize: 15,
            color: Colors.white,
          ),
          textAlign: TextAlign.left,
        ),
      ),
    );
  }
}
