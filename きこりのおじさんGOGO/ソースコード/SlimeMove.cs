using UnityEngine;
using System.Collections;

public class SlimeMove : MonoBehaviour {

    private int move_x_rand, move_z_rand;
    private int interval;
    public float v = 0;

    // Use this for initialization
    void Start ()
    {
        interval = 0;

    }
	
	// Update is called once per frame
	void Update () {

        Vector3 pos = transform.position;

        if (interval <= 0)
        {
            move_x_rand = Random.Range(0, 3);
            move_z_rand = Random.Range(0, 3);
            interval = 60;
        }

        interval--;

        if (move_x_rand == 0) pos.x += v;
        if (move_x_rand == 1) pos.x -= v;

        if (move_z_rand == 0) pos.z += v;
        if (move_z_rand == 1) pos.z -= v;

        if (pos.x > 20) pos.x = 20;
        if (pos.x < -20) pos.x = -20;
        if (pos.z > 20) pos.z = 20;
        if (pos.z < -20) pos.z = -20;

        transform.position = pos;
    }
}
